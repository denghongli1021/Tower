#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "WoodBullet.hpp"
#include "Group.hpp"
#include "ToolMove.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "ExplosionEffect.hpp"


const int ToolMove::Price = 0;
ToolMove::ToolMove(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    //Tool("play/Move.png", x, y, Price, 2)
    Turret("play/white.png", "play/Move.png", x, y, 0, Price, 0) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
}

void ToolMove::CreateBullet() {

}

