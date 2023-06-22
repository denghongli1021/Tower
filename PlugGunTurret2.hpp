#ifndef PLUGGUNTURRET2_HPP
#define PLUGGUNTURRET2_HPP
#include "Turret.hpp"

class PlugGunTurret2 : public Turret {
public:
    static const int Price;
    PlugGunTurret2(float x, float y);
    void CreateBullet() override;
};

class PlugGunTurret5 : public Turret {
public:
    int i =0; // state
    static const int Price;
    PlugGunTurret5(float x, float y);
    void CreateBullet() override;
};
#endif // PLUGGUNTURRET_HPP

