#include "DNN_armor.hpp"

namespace DNN_armor
{
    DNN_Dectect::DNN_Dectect(std::string input_path)
    {
        cv::FileStorage config_read(input_path, cv::FileStorage::READ);
        config_read["DEBUG_MODE"] >> DNN_Config_.debug_mode;
        config_read["MAX_HEIGHT"] >> DNN_Config_.max_height;
        config_read["MIN_HEIGHT"] >> DNN_Config_.min_height;
        config_read["MAX_WIDTH"] >> DNN_Config_.max_width;
        config_read["MIN_WIDTH"] >> DNN_Config_.min_width;
    }

    DNN_Model::DNN_Model(std::string input_path)
    {
        DNN_Model::load(input_path);
        DNN_Model::layers();
    }

    inline void DNN_Model::load(std::string onnx_model_path)
    {
        std::cout << "[OOI] opencv version: " << cv::getVersionString() << std::endl;
        
        model_path = onnx_model_path;
        opencv_net = cv::dnn::readNetFromONNX(model_path);
        std::cout << "[OOI] Load Success" << std::endl;
        if (!opencv_net.empty())
        {
            std::cout << "[OOI] load model success: " << model_path << std::endl;
        }
        else
        {
            std::cout << "[OOI] load model failed: " << model_path << std::endl;
            return;
        }
#if __has_include(<opencv2/gpu/gpu.hpp>)
        opencv_net.setPreferableBackend(cv::dnn::DNN_TARGET_CUDA);
#else
        opencv_net.setPreferableBackend(cv::dnn::DNN_TARGET_CPU);
#endif
    }

    inline void DNN_Model::layers(void)
    {
        if (opencv_net.empty())
        {
            std::cout << "[OOI] model is empty" << std::endl;
            return;
        }

        std::cout << "[OOI] model from " << model_path << " has layers: " << std::endl;
        for (const auto &layer_name : opencv_net.getLayerNames())
        {
            std::cout << "\t\t" << layer_name << std::endl;
        }
    }
}