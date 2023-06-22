#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "WoodBullet.hpp"
#include "Group.hpp"
#include "ToolShovel.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "ExplosionEffect.hpp"


const int ToolShovel::Price = 0;
ToolShovel::ToolShovel(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    //Tool("play/Shovel.png", x, y, Price, 2)
    Turret("play/white.png", "play/shovel.png", x, y, 0, Price, 0) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();

}

void ToolShovel::CreateBullet() {

}


