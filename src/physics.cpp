#include "../include/physics.h"
#include "../include/constants.h"
#include <random>

void init_physics(PhysicsState& state) {
    // 生成随机碰撞高度
    static std::mt19937 gen(std::random_device{}());
    std::uniform_real_distribution<double> dist(-DISK_RADIUS*0.8, DISK_RADIUS*0.8);
    state.impact_radius = dist(gen) * PIXEL_TO_METER;

    // 计算初始角动量
    state.L_initial = state.bullet_mass * state.bullet_velocity * state.impact_radius;

    // 计算碰撞后参数
    const double I_disk = 0.5 * DISK_MASS * pow(DISK_RADIUS*PIXEL_TO_METER, 2);
    const double I_bullet = state.bullet_mass * pow(state.impact_radius, 2);
    state.omega = state.L_initial / (I_disk + I_bullet);
    state.L_final = state.L_initial; // 角动量守恒
}