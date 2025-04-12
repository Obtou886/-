#include <iostream>
#include <opencv2/opencv.hpp>
#include "../include/graphics.h"
#include "../include/physics.h"
#include "../include/constants.h"

int main() {
int TRY;

    PhysicsState pstate;
    std::cout << "子弹质量 (3-12克): ";
    std::cin >> pstate.bullet_mass;
    while (pstate.bullet_mass < 3 || pstate.bullet_mass > 12) {
        std::cout << "子弹质量超出正常步枪子弹范围输入，请重新输入3到12这一范围质量!" << std::endl;
        std::cout << "子弹质量 (3-12克): ";
        std::cin >> pstate.bullet_mass;
    }
// if(pstate.bullet_mass< 3|| pstate.bullet_mass > 12){
//     std::cout << "子弹质量超出正常步枪子弹范围输入，请重新输入3到12这一范围质量!" << std::endl;
//     std::cout << "子弹质量 (3-12克): ";
//     std::cin >> pstate.bullet_mass;}

    pstate.bullet_mass /= 1000;
    
    std::cout << "子弹速度 (700-900 m/s): ";
    std::cin >> pstate.bullet_velocity;
  while (pstate.bullet_velocity < 700 || pstate.bullet_velocity > 900)
  {
    std::cout << "子弹速度超出正常步枪子弹范围输入，请重新输入700到900这一范围速度!" << std::endl;
    std::cout << "子弹速度 (700-900 m/s): ";
    std::cin >> pstate.bullet_velocity;
  }
  
// if(pstate.bullet_velocity< 700|| pstate.bullet_velocity > 900){
//     std::cout << "子弹速度超出正常步枪子弹范围输入，请重新输入700到900这一范围速度!" << std::endl;
//     std::cout << "子弹速度 (700-900 m/s): ";
//     std::cin >> pstate.bullet_velocity;}

    init_physics(pstate);//初始化物理状态

    GraphicsState gstate;//初始化图像状态
    init_graphics(gstate, pstate);
    
    cv::Mat canvas(WINDOW_HEIGHT, WINDOW_WIDTH, CV_8UC3);
    cv::namedWindow("角动量守恒演示", cv::WINDOW_AUTOSIZE);

    while (true) {
        update_graphics(gstate, pstate);
        draw_scene(canvas, gstate, pstate);
        
        cv::imshow("角动量守恒演示", canvas);
        if (cv::waitKey(30) == 'q') break;//按q退出
    }
    cv::destroyAllWindows();
std::cout << "想再试一试按1后再按enter键哦" << std::endl;
std::cin >> TRY;
if(TRY == 1){
    main();
}
else{
    return 0;
}
}