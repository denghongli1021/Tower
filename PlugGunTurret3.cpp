#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "WoodBullet3.hpp"
#include "Group.hpp"
#include "PlugGunTurret3.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "ShootEffect.hpp"


const int PlugGunTurret3::Price = 100;
PlugGunTurret3::PlugGunTurret3(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/tower-base.png", "play/turret-1.png", x, y, 700, Price, 3) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
}
const int PlugGunTurret4::Price = 200;
PlugGunTurret4::PlugGunTurret4(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/tower-base.png", "play/turret-2.png", x, y, 700, Price, 3) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
}

void PlugGunTurret3::CreateBullet() {
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    // Change bullet position to the front of the gun barrel.
    getPlayScene()->BulletGroup->AddNewObject(new WoodBullet3(Position + normalized * 36, diff, rotation, this));
    // TODO 4 (2/2): Add a ShootEffect here. Remember you need to include the class.
    getPlayScene()->EffectGroup->AddNewObject(new ShootEffect(Position.x+ normalized.x * 36, Position.y+ normalized.y * 36));
    AudioHelper::PlayAudio("gun.wav");
}

void PlugGunTurret4::CreateBullet() {
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    // Change bullet position to the front of the gun barrel.
    Engine::Point perpendicular = Engine::Point(-normalized.y, normalized.x);  // 計算垂直方向的向量
    Engine::Point Position2 = Position + perpendicular *10;
    Engine::Point Position3 = Position - perpendicular *10;

    getPlayScene()->BulletGroup->AddNewObject(new WoodBullet3(Position2 + normalized * 36, diff, rotation, this));
    getPlayScene()->BulletGroup->AddNewObject(new WoodBullet3(Position3 + normalized * 36, diff, rotation, this));
    // TODO 4 (2/2): Add a ShootEffect here. Remember you need to include the class.
    getPlayScene()->EffectGroup->AddNewObject(new ShootEffect(Position.x+ normalized.x * 36, Position.y+ normalized.y * 36));
    AudioHelper::PlayAudio("gun.wav");
}


