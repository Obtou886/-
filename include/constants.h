#pragma once
#include <opencv2/opencv.hpp>

//自定义 窗口参数
constexpr int WINDOW_WIDTH = 1024;
constexpr int WINDOW_HEIGHT = 768;

// 圆盘参数
constexpr double DISK_MASS = 1.0;         // kg
constexpr int DISK_RADIUS = 120;           // pixels
const cv::Point DISK_CENTER(800, 384);    // 窗口右侧区域

// 圆型子弹参数
constexpr int BULLET_RADIUS = 10;//半径
constexpr int BULLET_SPEED_PX = 15;       // 像素/帧
constexpr double PIXEL_TO_METER = 0.01;   // 1像素=0.01米

// 显示参数
const cv::Point INFO_POS(20, 40);
const cv::Point ANGULAR_POS(20, 70);
constexpr double FONT_SCALE = 0.85;
constexpr int FONT_THICKNESS = 2;

// 自定义颜色定义
namespace Colors {
    const cv::Scalar fomula(200, 0, 99);//公式颜色
    const cv::Scalar explanation(0, 200, 20);//公式解释颜色
    const cv::Scalar Not(0, 0, 255);//标语颜色
    const cv::Scalar BACKGROUND(240, 240, 240);//背景颜色
    const cv::Scalar DISK_FILL(200, 200, 255);//圆盘颜色
    const cv::Scalar DISK_BORDER(0, 0, 200);//圆盘边框颜色
    const cv::Scalar BULLET_COLOR(0, 200, 0);//子弹颜色
    const cv::Scalar TEXT_COLOR(44, 77, 0);//文字颜色
}