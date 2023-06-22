#ifndef TOOLSHOVEL_HPP
#define TOOLSHOVEL_HPP
#include "Turret.hpp"

class ToolShovel : public Turret {
public:
    static const int Price;
    ToolShovel(float x, float y);
    void CreateBullet() override ;
    //const bool Preview = false;
};
#endif // PLUGGUNTURRETMOVE_HPP


