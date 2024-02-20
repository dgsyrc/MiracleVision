#pragma once

#include <fmt/color.h>
#include <fmt/core.h>

#include <string>
#include <iostream>
#include <opencv2/opencv.hpp>

namespace DNN_armor
{
    struct DNN_Data
    {
        int debug_mode;
        int max_height;
        int min_height;
        int max_width;
        int min_width;
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
    };
}