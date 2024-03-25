#pragma once

#include <string>
#include <vector>
#include <queue>

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
        static void imWindow(std::string window_name, cv::Mat &src_img, SIZE size, bool if_destroy = false)
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
            if (if_destroy)
            {
                cv::destroyWindow(window_name);
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

        static std::string formatDobleValue(double val, int fixed)
        {
            std::string str = std::to_string(val);
            if (fixed == 0)
            {
                return std::to_string(int(val));
            }
            return str.substr(0, str.find(".") + fixed + 1);
        }

        static std::string formatFloatValue(float val, int fixed)
        {
            std::string str = std::to_string(val);
            if (fixed == 0)
            {
                return std::to_string(int(val));
            }
            return str.substr(0, str.find(".") + fixed + 1);
        }

        static void drawDiagram(std::string window_name, std::queue<float> &data, SIZE size, float add_data, std::string x_axis_name, std::string y_axis_name, int y_domain, cv::Scalar color = cv::Scalar(255, 0, 0))
        {
            int width;
            int height;
            int plotWidth;
            int plotHeight;
            int min_data;
            int max_data;
            int data_size;
            cv::Point origin;
            std::vector<float> vec_data;
            vec_data.clear();
            data.push(add_data);
            switch (size)
            {
            case SMALL:
                width = 400;
                height = 300;
                plotWidth = 350;
                plotHeight = 250;
                origin = {30, 270};
                if (data.size() > 600)
                {
                    data.pop();
                }
                break;
            case MEDIUM:
                width = 800;
                height = 600;
                plotWidth = 700;
                plotHeight = 500;
                origin = {50, 550};
                if (data.size() > 900)
                {
                    data.pop();
                }
                break;
            case BIG:
                width = 1200;
                height = 900;
                plotWidth = 1050;
                plotHeight = 750;
                origin = {80, 820};
                if (data.size() > 1200)
                {
                    data.pop();
                }
                break;
            default:
                fmt::print("[{}] initDiagram() can't use FIX_MEDIUM window size\n", err_idntifier);
                return;
            }

            data_size = data.size();
            for (int i = 1; i <= data_size; ++i)
            {
                float tmp = data.front();
                data.pop();
                data.push(tmp);
                vec_data.push_back(tmp);
            }
            min_data = int(*std::min_element(vec_data.begin(), vec_data.end()) * y_domain);
            max_data = int(*std::max_element(vec_data.begin(), vec_data.end()) * y_domain);
            cv::Mat canvas = cv::Mat::zeros(height, width, CV_8UC3);
            canvas = cv::Scalar(255, 255, 255);
            cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);

            // Draw axes

            drawAxis(canvas, origin, plotWidth, plotHeight, cv::Scalar(0, 0, 0), 2, y_domain);
            addLabels(canvas, origin, plotWidth, plotHeight, x_axis_name, y_axis_name);

            // Draw graph
            drawGraph(canvas, vec_data, color, origin, plotWidth, plotHeight);
            addInfo(canvas, min_data, max_data);
            cv::imshow(window_name, canvas);
            cv::waitKey(30);
        }

    private:
        inline static void drawAxis(cv::Mat &img, cv::Point origin, int &width, int &height, cv::Scalar color, int thickness, int &y_domin)
        {
            int stepSize = height / 10.0;
            int fixed = 0;
            // Draw x-axis
            cv::line(img, origin, cv::Point(origin.x + width, origin.y), color, thickness);
            // Draw y-axis
            cv::line(img, origin, cv::Point(origin.x, origin.y - height), color, thickness);
            if (std::to_string(y_domin).size() <= 3)
            {
                fixed = 4 - std::to_string(y_domin).size();
            }
            for (int i = 0; i <= 10; ++i)
            {
                cv::putText(img, formatFloatValue(y_domin * 1.0 / 10.0 * i, fixed), cv::Point(origin.x - 30, origin.y - stepSize * i), cv::FONT_HERSHEY_SIMPLEX, 0.3, cv::Scalar(0, 0, 0));
                cv::line(img, cv::Point(origin.x, origin.y - stepSize * i), cv::Point(origin.x + 10, origin.y - stepSize * i), color, thickness);
            }
        }

        inline static void drawGraph(cv::Mat &img, std::vector<float> &data, cv::Scalar color, cv::Point &origin, int &plotWidth, int &plotHeight)
        {
            const int numPoints = data.size();
            const float stepSize = plotWidth * 1.0 / (numPoints - 1);
            for (int i = 0; i < numPoints - 1; ++i)
            {
                int P1, P2;
                P1 = int(data[i] * plotHeight);
                P2 = int(data[i + 1] * plotHeight);
                cv::Point p1(int(origin.x + i * stepSize), img.rows - origin.x - P1);
                cv::Point p2(int(origin.x + (i + 1) * stepSize), img.rows - origin.x - P2);
                line(img, p1, p2, color, 1);
            }
        }

        inline static void addLabels(cv::Mat &img, cv::Point origin, int width, int height, std::string xLabel, std::string yLabel)
        {
            cv::putText(img, xLabel, cv::Point(origin.x + width - 20, origin.y + 20), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0));
            cv::putText(img, yLabel, cv::Point(origin.x + 10, origin.y - height - 10), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0));
        }

        inline static void addInfo(cv::Mat &img, int min_data, int max_data)
        {

            cv::putText(img, fmt::format("min:{}", min_data), cv::Point(img.cols - 80, 30), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0));
            cv::putText(img, fmt::format("max:{}", max_data), cv::Point(img.cols - 80, 60), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0));
        }
    };
};