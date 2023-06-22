#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "WoodBullet2.hpp"
#include "Group.hpp"
#include "PlugGunTurret2.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "ShootEffect.hpp"


const int PlugGunTurret2::Price = 60;
PlugGunTurret2::PlugGunTurret2(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/tower-base.png", "play/turret-5.png", x, y, 500, Price, 2) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
}
void PlugGunTurret2::CreateBullet() {
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    // Change bullet position to the front of the gun barrel.
    getPlayScene()->BulletGroup->AddNewObject(new WoodBullet2(Position + normalized * 36, diff, rotation, this));
    // TODO 4 (2/2): Add a ShootEffect here. Remember you need to include the class.
    getPlayScene()->EffectGroup->AddNewObject(new ShootEffect(Position.x+ normalized.x * 36, Position.y+ normalized.y * 36));
    AudioHelper::PlayAudio("gun.wav");
}

const int PlugGunTurret5::Price = 80;
PlugGunTurret5::PlugGunTurret5(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/tower-base.png", "play/fort.png", x, y, 200, Price, 0) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
}
void PlugGunTurret5::CreateBullet() {
//    for (int i = 0; i < numBullets; i++) {
//        Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
//        float rotation = atan2(diff.y, diff.x);
//        Engine::Point normalized = diff.Normalize();
//        // Change bullet position to the front of the gun barrel.
//        getPlayScene()->BulletGroup->AddNewObject(new WoodBullet2(Position + normalized * 36, diff, rotation, this));
//        // TODO 4 (2/2): Add a ShootEffect here. Remember you need to include the class.
//        getPlayScene()->EffectGroup->AddNewObject(new ShootEffect(Position.x + normalized.x * 36, Position.y + normalized.y * 36));
//        AudioHelper::PlayAudio("gun.wav");
//    }
    //std::cout << "Creating Bullest (turret 5)" << bulletcount << '\n' ;
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    Engine::Point perpendicular = Engine::Point(-normalized.y, normalized.x);
    // Change bullet position to the front of the gun barrel.
    //std::cout << "Rotation : " << rotation << "\n" ;
    if (bulletcount == 0 && i <= 1) {
        //std::cout << "Creating  0 \n" ;
        getPlayScene()->BulletGroup->AddNewObject(new WoodBullet4(Position + normalized * 36, diff, 0.0, this));
        getPlayScene()->BulletGroup->AddNewObject(new WoodBullet4(Position + perpendicular * 36, diff- diff, ALLEGRO_PI / 2 , this));
        getPlayScene()->BulletGroup->AddNewObject(new WoodBullet4(Position + normalized* -1 * 36, diff- diff, ALLEGRO_PI  , this));
        getPlayScene()->BulletGroup->AddNewObject(new WoodBullet4(Position + perpendicular* -1 * 36, diff- diff, ALLEGRO_PI * 1.5, this));
        //AudioHelper::PlayAudio("gun.wav");
        bulletcount = 8;
        i++;
    }
    else if (bulletcount == 0 && i <= 2) {
        //std::cout << "Creating  1 \n" ;
        //std::cout << "Before make bullet :" << bulletcount << "\n" ;
        getPlayScene()->BulletGroup->AddNewObject(new WoodBullet4(Position + normalized * 36, diff - diff, 0.0, this));
        getPlayScene()->BulletGroup->AddNewObject(new WoodBullet4(Position + perpendicular * 36, diff- diff, ALLEGRO_PI / 2 , this));
        getPlayScene()->BulletGroup->AddNewObject(new WoodBullet4(Position + normalized* -1 * 36, diff- diff, ALLEGRO_PI  , this));
        getPlayScene()->BulletGroup->AddNewObject(new WoodBullet4(Position + perpendicular* -1 * 36, diff- diff, ALLEGRO_PI * 1.5, this));
        //AudioHelper::PlayAudio("gun.wav");
        bulletcount = 4;
        i = 3;
        //std::cout << "After make bullet :" << bulletcount << "\n" ;
    }
    else if (bulletcount == 0) {
        //std::cout << "Creating  2 \n" ;
        getPlayScene()->BulletGroup->AddNewObject(new WoodBullet4(Position + normalized * 36, diff - diff, 0.0, this));
        getPlayScene()->BulletGroup->AddNewObject(new WoodBullet4(Position + perpendicular * 36, diff- diff, ALLEGRO_PI / 2 , this));
        getPlayScene()->BulletGroup->AddNewObject(new WoodBullet4(Position + normalized* -1 * 36, diff- diff, ALLEGRO_PI  , this));
        getPlayScene()->BulletGroup->AddNewObject(new WoodBullet4(Position + perpendicular* -1 * 36, diff- diff, ALLEGRO_PI * 1.5, this));
        //AudioHelper::PlayAudio("gun.wav");
        bulletcount = 4;
    }
    // TODO 4 (2/2): Add a ShootEffect here. Remember you need to include the class.
    //getPlayScene()->EffectGroup->AddNewObject(new ShootEffect(Position.x+ normalized.x * 36, Position.y+ normalized.y * 36));
}


