#include "../include/graphics.h"
#include "../include/constants.h"

void init_graphics(GraphicsState& gstate, const PhysicsState& pstate) {
    gstate.bullet_pos = cv::Point(0, DISK_CENTER.y - static_cast<int>(pstate.impact_radius / PIXEL_TO_METER));
}

void update_graphics(GraphicsState& gstate, const PhysicsState& pstate) {
    if (!gstate.collision_occurred) {
        gstate.bullet_pos.x += BULLET_SPEED_PX;
        
        // 精确碰撞检测
        if (cv::norm(gstate.bullet_pos - DISK_CENTER) < DISK_RADIUS-15 /*+ BULLET_RADIUS*/) {
            gstate.collision_occurred = true;
        }
    } else {
        // 更新旋转角度（顺时针）
        gstate.rotation_angle += pstate.omega * 180/CV_PI * 0.03; // 速度因子
        if(gstate.rotation_angle >= 360) gstate.rotation_angle -= 360;
    }
}

void draw_scene(cv::Mat& canvas, const GraphicsState& gstate, const PhysicsState& pstate) {
    canvas.setTo(Colors::BACKGROUND);

    // 绘制圆盘
    cv::circle(canvas, DISK_CENTER, DISK_RADIUS, Colors::DISK_FILL, cv::FILLED);
    cv::circle(canvas, DISK_CENTER, DISK_RADIUS, Colors::DISK_BORDER, 2);

    // 绘制子弹
    cv::Point final_bullet_pos = gstate.bullet_pos;
    if (gstate.collision_occurred) {
        // 计算旋转后的子弹位置
        double radian = gstate.rotation_angle * CV_PI/180;
         int offset_x = (DISK_RADIUS /*+ 15*/) * cos(radian);
        int offset_y = (DISK_RADIUS /*+ 15*/) * sin(radian);
        final_bullet_pos = DISK_CENTER + cv::Point(offset_x, offset_y);
    }
    cv::circle(canvas, final_bullet_pos, BULLET_RADIUS, Colors::BULLET_COLOR, cv::FILLED);

    // 显示参数
    std::string info = cv::format("Mass: %.1fg  Speed: %.0fm/s", 
                                 pstate.bullet_mass*1000, pstate.bullet_velocity);
    cv::putText(canvas, info, INFO_POS, 
               cv::FONT_HERSHEY_SIMPLEX, FONT_SCALE, Colors::TEXT_COLOR, FONT_THICKNESS);

    std::string angular_info = cv::format("Initial L: %.3f  Final L: %.3f (kg*m^2/s)", 
                                        pstate.L_initial, pstate.L_final);
    cv::putText(canvas, angular_info, ANGULAR_POS, 
               cv::FONT_HERSHEY_SIMPLEX, FONT_SCALE, Colors::TEXT_COLOR, FONT_THICKNESS);

std::string fomula_J_b =cv::format("J_bullet=Mass*r^2 ")    ;
cv::putText(canvas,fomula_J_b,cv::Point(20,100) ,
cv::FONT_HERSHEY_SIMPLEX, FONT_SCALE, Colors::fomula, FONT_THICKNESS);

std::string fomula_j_d=cv::format("J_disk=0.5*Mass*r^2==0")    ;
cv::putText(canvas,fomula_j_d,cv::Point(20,130) ,
cv::FONT_HERSHEY_SIMPLEX, FONT_SCALE, Colors::fomula, FONT_THICKNESS);

std::string fomula_L =cv::format("L=J*omega")  ;     
cv::putText(canvas,fomula_L,cv::Point(20,160) ,
cv::FONT_HERSHEY_SIMPLEX, FONT_SCALE, Colors::fomula, FONT_THICKNESS);

std::string Cause =cv::format("Because angular momentum is conserved : J_1*omega_1=J_2*omega_2")    ;
cv::putText(canvas,Cause,cv::Point(20,190) ,
cv::FONT_HERSHEY_SIMPLEX, FONT_SCALE, Colors::explanation, FONT_THICKNESS);

std::string Not =cv::format("Clockwise as positive direction")    ;
cv::putText(canvas,Not,cv::Point(300,15) ,
cv::FONT_HERSHEY_SIMPLEX, 0.7, Colors::Not, FONT_THICKNESS);
}