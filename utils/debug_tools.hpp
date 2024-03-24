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

        static void drawDiagram(std::string window_name, std::queue<float> &data, SIZE size, float add_data, std::string x_axis_name, std::string y_axis_name)
        {
            int width;
            int height;
            int plotWidth;
            int plotHeight;
            cv::Point origin;
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
            cv::Mat canvas = cv::Mat::zeros(height, width, CV_8UC3);
            canvas = cv::Scalar(255, 255, 255);
            cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);

            // Draw axes

            drawAxis(canvas, origin, plotWidth, plotHeight, cv::Scalar(0, 0, 0), 2);
            addLabels(canvas, origin, plotWidth, plotHeight, x_axis_name, y_axis_name);

            // Draw graph
            drawGraph(canvas, data, cv::Scalar(255, 0, 0), origin, plotWidth, plotHeight);

            cv::imshow(window_name, canvas);
            cv::waitKey(30);
        }

    private:
        static void drawAxis(cv::Mat &img, cv::Point origin, int width, int height, cv::Scalar color, int thickness)
        {
            // Draw x-axis
            cv::line(img, origin, cv::Point(origin.x + width, origin.y), color, thickness);
            // Draw y-axis
            cv::line(img, origin, cv::Point(origin.x, origin.y - height), color, thickness);
        }

        static void drawGraph(cv::Mat &img, std::queue<float> &data, cv::Scalar color, cv::Point &origin, int &plotWidth, int &plotHeight)
        {
            const int numPoints = data.size();
            const float stepSize = plotWidth * 1.0 / (numPoints - 1);
            int i = 0;
            while (numPoints - 1 > i)
            {
                int P1, P2;
                float tmp;
                tmp = data.front();
                data.push(tmp);
                P1 = int(tmp * plotHeight);
                data.pop();
                tmp = data.front();
                P2 = int(tmp * plotHeight);
                cv::Point p1(int(origin.x + i * stepSize), img.rows - origin.x - P1);
                cv::Point p2(int(origin.x + (i + 1) * stepSize), img.rows - origin.x - P2);
                line(img, p1, p2, color, 1);
                i++;
            }
            data.push(data.front());
            data.pop();
        }

        static void addLabels(cv::Mat &img, cv::Point origin, int width, int height, std::string xLabel, std::string yLabel)
        {
            cv::putText(img, xLabel, cv::Point(origin.x + width - 20, origin.y + 20), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0));
            cv::putText(img, yLabel, cv::Point(origin.x + 10, origin.y - height - 10), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0));
        }
    };
};