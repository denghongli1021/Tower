#ifndef PLUGGUNTURRETMOVE_HPP
#define PLUGGUNTURRETMOVE_HPP
#include "Turret.hpp"

class PlugGunTurretMove : public Turret {
public:
    static const int Price;
    PlugGunTurretMove(float x, float y);
    void CreateBullet() override ;
    //const bool Preview = false;
};
#endif // PLUGGUNTURRETMOVE_HPP
