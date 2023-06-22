#ifndef TOOLMOVE_HPP
#define TOOLMOVE_HPP
#include "Turret.hpp"

class ToolMove : public Turret {
public:
    static const int Price;
    ToolMove(float x, float y);
    void CreateBullet() override ;
    //const bool Preview = false;
};
#endif // PLUGGUNTURRETMOVE_HPP

