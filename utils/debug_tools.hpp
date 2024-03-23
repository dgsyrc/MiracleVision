#pragma once

#include <string>

#include <fmt/core.h>
#include <fmt/color.h>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

namespace tools
{
    auto err_idntifier = fmt::format(fg(fmt::color::red) | fmt::emphasis::bold, "ERROR");
    auto rec_idntifier = fmt::format(fg(fmt::color::green) | fmt::emphasis::bold, "RecordInfo");
    class Tools
    {
    public:
        Tools(){};
        enum SIZE
        {
            SMALL,
            MEDIUM,
            BIG,
            FIX_MEDIUM
        };
        static void imWindow(std::string window_name, cv::Mat &src_img, SIZE size)
        {
            cv::Mat tmp;
            cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);
            switch (size)
            {
            case SMALL:
                cv::resize(src_img, tmp, cv::Size(int(src_img.cols * 0.3), int(src_img.rows * 0.3)));
                cv::imshow(window_name, tmp);
                cv::waitKey(30);
                break;
            case MEDIUM:
                cv::resize(src_img, tmp, cv::Size(int(src_img.cols * 0.6), int(src_img.rows * 0.6)));
                cv::imshow(window_name, tmp);
                cv::waitKey(30);
                break;
            case BIG:
                tmp = src_img;
                cv::imshow(window_name, tmp);
                cv::waitKey(30);
                break;
            case FIX_MEDIUM:
                cv::resizeWindow(window_name, cv::Size(512, 512));
                cv::resize(src_img, tmp, cv::Size(int(src_img.cols * 0.6), int(src_img.rows * 0.6)));
                cv::imshow(window_name, tmp);
                cv::waitKey(30);
                break;
            default:
                break;
            }
        }

        static void recordInit(std::string video_name, cv::VideoWriter &writer, cv::Size frame_size, int fps)
        {
            writer.open(video_name, cv::VideoWriter::fourcc('m', 'p', '4', 'v'), fps, frame_size);
            if (!writer.isOpened())
            {
                fmt::print("[{}] Can't create video file\n", err_idntifier);
            }
            else
            {
                fmt::print("[{}] {}\n", rec_idntifier, video_name);
            }
        }
    };
};