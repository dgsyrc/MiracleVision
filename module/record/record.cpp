/**
 * @file record.cpp
 * @author dgsyrc (yrcminecraft@foxmail.com)
 * @brief record mode
 * @date 2024-02-20
 * @copyright Copyright (c) 2024 dgsyrc
 *
 */
#include "record.hpp"

#include <iostream>

namespace RecordMode
{
    Record::Record() {}
    Record::Record(std::string path_input, std::string path_in, cv::Size size)
    {
        video_save_path_ = path_input;
    }
    Record::~Record() {}

} // namespace RecordMode
