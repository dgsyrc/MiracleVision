#pragma once

#include <fmt/color.h>
#include <fmt/core.h>

#include <string>
#include <iostream>
#include <opencv2/opencv.hpp>

#include <onnxruntime/onnxruntime_cxx_api.h>
#include <onnxruntime/onnxruntime_c_api.h>

namespace DNN_armor
{
    auto idntifier = fmt::format(fg(fmt::color::green) | fmt::emphasis::bold, "DNN_INFO");
    struct DNN_Data
    {
        int debug_mode;
        int height;
        int width;
    };
    class DNN_Dectect
    {
    public:
        DNN_Dectect(std::string input_path);

    private:
        DNN_Data DNN_Config_;
    };
    class DNN_Model
    {
    public:
        DNN_Model(std::string input_path);
        inline void load(std::string onnx_model_path);
        inline void layers(void);
        void printModelInfo(Ort::Session &session, Ort::AllocatorWithDefaultOptions &allocator);

    private:
        std::string model_path;
    };
}