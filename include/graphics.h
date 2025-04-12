#pragma once
#include "physics.h"
#include <opencv2/opencv.hpp>
struct GraphicsState {
    cv::Point bullet_pos;
    double rotation_angle = 0.0;
    bool collision_occurred = false;
};

void init_graphics(GraphicsState& gstate, const PhysicsState& pstate);//初始化图像
void update_graphics(GraphicsState& gstate, const PhysicsState& pstate);//更新图像
void draw_scene(cv::Mat& canvas, const GraphicsState& gstate, const PhysicsState& pstate);//绘制场景