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
}