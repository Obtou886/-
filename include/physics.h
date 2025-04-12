#pragma once

struct PhysicsState {
    double bullet_mass;      // kg
    double bullet_velocity; // m/s
    double impact_radius;   // 碰撞点半径（米）
    double omega;           // 角速度 rad/s
    double L_initial;       // 初始角动量
    double L_final;         // 碰撞后角动量
};

void init_physics(PhysicsState& state);