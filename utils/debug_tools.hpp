#pragma once

#include <string>


#include <fmt/core.h>
#include <fmt/color.h>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

namespace tools
{

    class Tools
    {
    public:
        Tools(){};
        enum SIZE
        {
            SMALL,
            MEDIUM,
            BIG,
        };
        static void imWindow(std::string window_name, cv::Mat &src_img, SIZE size)
        {
            cv::Mat tmp;
            cv::namedWindow(window_name);
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
            default:
                break;
            }
        }

        static void recInit(std::string video_name)
        {
            
        }
    };
};