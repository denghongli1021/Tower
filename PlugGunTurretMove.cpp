#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "WoodBullet.hpp"
#include "Group.hpp"
#include "PlugGunTurretMove.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "ExplosionEffect.hpp"


const int PlugGunTurretMove::Price = 0;
PlugGunTurretMove::PlugGunTurretMove(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/tower-base.png", "play/Move.png", x, y, 0, Price, 2) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
}

void PlugGunTurretMove::CreateBullet() {

}
