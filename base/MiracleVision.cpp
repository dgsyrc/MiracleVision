/**
 * @file MiracleVision.cpp
 * @author dgsyrc (yrcminecraft@foxmail.com)
 * @brief Main Function
 * @date 2024-02-20
 * @copyright Copyright (c) 2024 dgsyrc
 */
#include "MiracleVision.hpp"

// video debug mode
#define VIDEO_DEBUG
#define RECORD

// auto fire
#define MANUAL_FIRE

// debug mode
// #define PARM_EDIT

// release mode
#define RELEASE

int main()
{
  // compile info
  fmt::print("[{}] MiracleVision built on g++ version: {}\n", idntifier, __VERSION__);
  fmt::print("[{}] MiracleVision config file path: {}\n", idntifier, CONFIG_FILE_PATH);

  cv::Mat src_img, roi_img;

#ifndef VIDEO_DEBUG
  mindvision::VideoCapture *mv_capture_ = new mindvision::VideoCapture(
      mindvision::CameraParam(0, mindvision::RESOLUTION_1280_X_1024, mindvision::EXPOSURE_2500));
  cv::VideoCapture cap_ = cv::VideoCapture(0);
#else

  cv::VideoCapture cap_(fmt::format("{}{}", SOURCE_PATH, "/video/armor.mp4"));

#endif
  fmt::print("Capture init pass.\n");
  // config file

  uart::SerialPort serial_ = uart::SerialPort(
      fmt::format("{}{}", CONFIG_FILE_PATH, "/serial/uart_serial_config.xml"));

  basic_armor::Detector basic_armor_ = basic_armor::Detector(
      fmt::format("{}{}", CONFIG_FILE_PATH, "/armor/basic_armor_config.xml"));

  basic_buff::Detector basic_buff_ = basic_buff::Detector(
      fmt::format("{}{}", CONFIG_FILE_PATH, "/buff/basic_buff_config.xml"));

  basic_pnp::PnP pnp_ = basic_pnp::PnP(fmt::format("{}{}", CONFIG_FILE_PATH, "/camera/mv_camera_config_407.xml"), fmt::format("{}{}", CONFIG_FILE_PATH, "/angle_solve/basic_pnp_config.xml"));

  // onnx_inferring::model model_ = onnx_inferring::model(fmt::format("{}{}", SOURCE_PATH, "/module/ml/mnist-8.onnx"));
  Ort::Env env(OrtLoggingLevel::ORT_LOGGING_LEVEL_WARNING, "PoseEstimate");
  Ort::SessionOptions session_options;
  session_options.SetGraphOptimizationLevel(GraphOptimizationLevel::ORT_ENABLE_ALL);

  DNN_armor::DNN_Model dnn_model = DNN_armor::DNN_Model(fmt::format("{}{}", SOURCE_PATH, "/module/armor/yolov8.onnx"), env, session_options);
  DNN_armor::DNN_Dectect dnn_armor = DNN_armor::DNN_Dectect(fmt::format("{}{}", CONFIG_FILE_PATH, "/armor/DNN_armor_config.xml"));

  angle_solve::solve solution;
  solution.set_config(fmt::format("{}{}", CONFIG_FILE_PATH, "/angle_solve/angle_solve_config.xml"));

  angle_solve::solve buff_solution;
  buff_solution.set_config(fmt::format("{}{}", CONFIG_FILE_PATH, "/angle_solve/buff_angle_solve_config.xml"));

  basic_roi::RoI save_roi;
  fps::FPS global_fps_;
  basic_roi::RoI roi_;
  std::time_t st_time = std::time(nullptr);
  while (true)
  {
    auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    rec_time++;
    fmt::print("[time] {}\n", rec_time);
#ifdef RELEASE
    if (rec_time > 5000)
    {
      // int i [[maybe_unused]] = std::system("reboot"); // camera disconnected -> reboot
    }
#endif
    // global_fps_.getTick();
    // new_buff::new_buff_fps.getTick();
#ifndef VIDEO_DEBUG
    if (mv_capture_->isindustryimgInput())
    {
      src_img = mv_capture_->image();
    }
    else
    {
      cap_.read(src_img);
    }
    cv::Size frameSize = {src_img.cols, src_img.rows};
    // cap_fps = cap_.get(cv::CAP_PROP_FPS);
    // cap_fps = 30;
#else
    cap_.read(src_img);

    cv::waitKey(30);
    cv::Size frameSize(cap_.get(cv::CAP_PROP_FRAME_WIDTH), cap_.get(cv::CAP_PROP_FRAME_HEIGHT));
    cap_fps = cap_.get(cv::CAP_PROP_FPS);
#endif
    if (!src_img.empty())
    {
#ifdef RECORD
      if (!test_fps && rec_cnt < 200)
      {
        rec_cnt++;
      }
      else
      {
        if (!test_fps)
        {
          std::time_t ed_time = std::time(nullptr);
          cap_fps = (int)(200.0 / (ed_time - st_time));
          test_fps = true;
          rec_cnt = 0;
        }
      }
      if (rec_cnt == 0 && test_fps)
      {
        std::stringstream tmp;
        tmp << std::put_time(std::localtime(&t), "%Y%m%d%H%M%S");
        std::string str_time = tmp.str();
        std::string video_name = fmt::format("{}/video/record/{}.mp4", SOURCE_PATH, str_time);
        cout << frameSize.width << ' ' << frameSize.height << ' ' << cap_fps << '\n';
        tools::Tools::recordInit(video_name, writer, frameSize, cap_fps);
        writer.write(src_img);
        rec_cnt++;
      }
      else
      {
        cout << "[REC] frame:" << rec_cnt << " fps:" << cap_fps << "\n";
        if (test_fps)
        {
          if (rec_cnt > cap_fps * 60 * 1)
          {
            writer.write(src_img);
            writer.release();
            rec_cnt = 0;
          }
          else
          {
            writer.write(src_img);
            rec_cnt++;
          }
        }
      }

#endif
#ifndef RELEASE
      cv::imshow("[origin]", src_img);
      cv::waitKey(30);
#endif
#ifdef PARM_EDIT
      // armor reference line
      cv::line(src_img, {1024, 0}, {1024, 1024}, cv::Scalar(255, 0, 255), 2);
      cv::imshow("[armor_parm_edit]", src_img);
      cv::waitKey(30);
#endif
      fire = false;
      serial_.updateReceiveInformation();
      switch (serial_.returnReceiveMode())
      {
      // basic auto aim mode
      case uart::AUTO_AIM:
        fmt::print("[{}] AUTO_AIM\n", idntifier);
        // dnn_armor.Detect(src_img, dnn_model);
        if (basic_armor_.runBasicArmor(src_img, serial_.returnReceive()) /*basic_armor_.sentryMode(src_img, serial_.returnReceive())*/)
        {
          solution.angleSolve(basic_armor_.returnFinalArmorRotatedRect(0), src_img.size().height, src_img.size().width, serial_);
        }
        serial_.updataWriteData(basic_armor_.returnArmorNum(), fire,
                                solution.returnYawAngle(),
                                solution.returnPitchAngle(),
                                basic_armor_.returnArmorCenter(0),
                                0);
        break;
      case uart::ENERGY_BUFF:
        if (basic_buff_.runTask(src_img, serial_.returnReceive()))
        {
          fmt::print("[buff] PASS\n");
          buff_solution.angleSolve(basic_buff_.returnObjectRect(), src_img.size().height, src_img.size().width, serial_);
          serial_.updataWriteData(1, basic_buff_.isfire(),
                                  buff_solution.returnYawAngle(),
                                  buff_solution.returnPitchAngle(),
                                  basic_buff_.returnObjectforUart(),
                                  0);
        }
        else
        {
          serial_.updataWriteData(0, 0, 0, 0, {0, 0}, 0);
        }
        break;
      case uart::RECORD_MODE:
        break;
      case uart::PLANE_MODE:
        break;
      // [Unresolved] add number identification
      case uart::SENTINEL_AUTONOMOUS_MODE:
        break;
      case uart::CAMERA_CALIBRATION:
        // cam::create_images(src_img);
        // cam::calibrate();
        // cam::auto_create_images(src_img);
        cam::assess(src_img);
        // cam::CalibrationEvaluate();
        break;
      default:
        break;
      }
    }
    else
    {
#ifdef VIDEO_DEBUG
      // cap_.open(fmt::format("{}{}", SOURCE_PATH, "/video/1080.mp4"));
#endif
    }
#ifndef VIDEO_DEBUG
    mv_capture_->cameraReleasebuff();
#endif
    basic_armor_.freeMemory(fmt::format("{}{}", CONFIG_FILE_PATH, "/armor/basic_armor_config_new.xml"));
    // watchdog for camera disconnected
    /*global_fps_.calculateFPSGlobal();*/
    if (global_fps_.returnFps() > 500)
    {
#ifndef VIDEO_DEBUG
      mv_capture_->~VideoCapture();
#endif
      static int counter_for_dev{100};
      static int counter_for_new{30};
      while (!utils::resetMVCamera())
      {
        if (!--counter_for_dev)
        {
          // int i [[maybe_unused]] = std::system("reboot");
        }
        usleep(100);
      }
      usleep(100);
#ifndef VIDEO_DEBUG
      mv_capture_ = new mindvision::VideoCapture(mindvision::CameraParam(
          0, mindvision::RESOLUTION_1280_X_800, mindvision::EXPOSURE_40000));
#endif
      if (!--counter_for_new)
      {
        // int i [[maybe_unused]] = std::system("reboot");
      }
    }
  }
  return 0;
}
