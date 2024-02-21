#include "DNN_armor.hpp"

namespace DNN_armor
{
    DNN_Dectect::DNN_Dectect(std::string input_path)
    {
        cv::FileStorage config_read(input_path, cv::FileStorage::READ);
        config_read["DEBUG_MODE"] >> DNN_Config_.debug_mode;
        config_read["HEIGHT"] >> DNN_Config_.height;
        config_read["WIDTH"] >> DNN_Config_.width;
    }

    void DNN_Dectect::Detect(cv::Mat &src_img, DNN_Model &model)
    {
        img = src_img;
        // input_tensor = prepareInput(img, DNN_Config_.width, DNN_Config_.height);
        Ort::Value input_tensor = prepare_input(src_img);
        std::vector<const char *> input_names = {"input"};
        std::vector<const char *> output_names = {"output"};
        output = model.session.Run(Ort::RunOptions{nullptr}, input_names.data(), &input_tensor, 1, output_names.data(), 1);
        std::vector<Ort::Value> squeezed_tensor;

        for (size_t i = 1; i < output.size(); ++i)
        {
            squeezed_tensor.push_back(output[i]);
        }
        
    }
    Ort::Value DNN_Dectect::prepare_input(cv::Mat &bgr_image)
    {
        std::vector<int64_t> input_shape = {1, 3, DNN_Config_.height, DNN_Config_.width};
        cv::Mat image;
        cv::cvtColor(bgr_image, image, cv::COLOR_BGR2RGB);
        cv::resize(image, image, cv::Size(DNN_Config_.width, DNN_Config_.height));
        image.convertTo(image, CV_32FC3, 1.0 / 255.0);
        std::vector<float> input_data;
        image.forEach<cv::Vec3f>([&](cv::Vec3f &pixel, const int *position)
                                 {
        input_data.push_back(pixel[0]);
        input_data.push_back(pixel[1]);
        input_data.push_back(pixel[2]); });
        Ort::MemoryInfo memory_info = Ort::MemoryInfo::CreateCpu(OrtDeviceAllocator, OrtMemTypeCPU);
        Ort::Value input_tensor = Ort::Value::CreateTensor<float>(memory_info, input_data.data(), input_data.size(), input_shape.data(), 4);
        return input_tensor;
    }

    float DNN_Dectect::iou(std::vector<float> &rec_1, std::vector<float> &rec_2)
    {
        float s_rec1 = (rec_1[2] - rec_1[0]) * (rec_1[3] - rec_1[1]);
        float s_rec2 = (rec_2[2] - rec_2[0]) * (rec_2[3] - rec_2[1]);
        float sum_s = s_rec1 + s_rec2;
        float left = std::max(rec_1[0], rec_2[0]);
        float right = std::min(rec_1[2], rec_2[2]);
        float bottom = std::max(rec_1[1], rec_2[1]);
        float top = std::min(rec_1[3], rec_2[3]);

        if (left >= right || top <= bottom)
        {
            return 0.0;
        }
        else
        {
            float inter = (right - left) * (top - bottom);
            float iou = (inter / (sum_s - inter)) * 1.0;
            return iou;
        }
    }

    cv::Mat DNN_Dectect::prepareInput(cv::Mat &src_img, int width, int height)
    {
        cv::Mat tmp_img;
        cv::cvtColor(src_img, tmp_img, cv::COLOR_BGR2RGB);
        cv::resize(tmp_img, tmp_img, cv::Size2f(width, height));
        tmp_img = tmp_img / 255.0;
        tmp_img = cv::dnn::blobFromImage(tmp_img);
        return tmp_img;
    }

    void DNN_Model::printModelInfo(Ort::Session &session, Ort::AllocatorWithDefaultOptions &allocator)
    {
        // 输出模型输入节点的数量
        size_t num_input_nodes = session.GetInputCount();
        size_t num_output_nodes = session.GetOutputCount();
        fmt::print("[{}] Number of input node is: {}\n", idntifier, num_input_nodes);
        fmt::print("[{}] Number of output node is: {}\n", idntifier, num_output_nodes);

        // 获取输入输出维度
        for (auto i = 0; i < num_input_nodes; i++)
        {
            std::vector<int64_t> input_dims = session.GetInputTypeInfo(i).GetTensorTypeAndShapeInfo().GetShape();
            fmt::print("\n[{}] input {} dim is: ", idntifier, i);
            for (auto j = 0; j < input_dims.size(); j++)
                std::cout << input_dims[j] << " ";
        }
        for (auto i = 0; i < num_output_nodes; i++)
        {
            std::vector<int64_t> output_dims = session.GetOutputTypeInfo(i).GetTensorTypeAndShapeInfo().GetShape();
            fmt::print("\n[{}] output {} dim is: ", idntifier, i);
            for (auto j = 0; j < output_dims.size(); j++)
                std::cout << output_dims[j] << " ";
        }
        // 输入输出的节点名
        std::cout << std::endl; // 换行输出
        for (auto i = 0; i < num_input_nodes; i++)
            fmt::print("[{}] The input op-name {} is: {}\n", idntifier, i, *session.GetInputNameAllocated(i, allocator));
        for (auto i = 0; i < num_output_nodes; i++)
            fmt::print("[{}] The output op-name {} is: {}\n", idntifier, i, *session.GetOutputNameAllocated(i, allocator));
        // input_dims_2[0] = input_dims_1[0] = output_dims[0] = 1;//batch size = 1
    }
}