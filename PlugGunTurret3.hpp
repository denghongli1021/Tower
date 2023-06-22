#ifndef PLUGGUNTURRET3_HPP
#define PLUGGUNTURRET3_HPP
#include "Turret.hpp"

class PlugGunTurret3 : public Turret {
public:
    static const int Price;
    PlugGunTurret3(float x, float y);
    void CreateBullet() override;
};

class PlugGunTurret4 : public Turret {
public:
    static const int Price;
    PlugGunTurret4(float x, float y);
    void CreateBullet() override;
};
#endif // PLUGGUNTURRET_HPP


