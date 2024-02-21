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

    DNN_Model::DNN_Model(std::string input_path)
    {
        DNN_Model::load(input_path);
        DNN_Model::layers();
    }

    inline void DNN_Model::load(std::string onnx_model_path)
    {
        Ort::Env env(OrtLoggingLevel::ORT_LOGGING_LEVEL_WARNING, "PoseEstimate");
        Ort::SessionOptions session_options;
        session_options.SetGraphOptimizationLevel(GraphOptimizationLevel::ORT_ENABLE_ALL);
        Ort::AllocatorWithDefaultOptions allocator;
        model_path = onnx_model_path;
        Ort::Session session(env, model_path.c_str(), session_options);
        fmt::print("[{}] Load Success, the model is: {}\n", idntifier, model_path);
        Ort::MemoryInfo memory_info = Ort::MemoryInfo::CreateCpu(OrtAllocatorType::OrtArenaAllocator, OrtMemType::OrtMemTypeDefault);
        printModelInfo(session, allocator);
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
    inline void DNN_Model::layers(void)
    {
    }
}