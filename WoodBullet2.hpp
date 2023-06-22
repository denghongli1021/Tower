#ifndef WOODBULLET2_HPP
#define WOODBULLET2_HPP
#include "Bullet.hpp"

class Enemy;
class Turret;
namespace Engine {
    struct Point;
}  // namespace Engine

class WoodBullet2 : public Bullet {
public:
    explicit WoodBullet2(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
    void OnExplode(Enemy* enemy) override;
};

class WoodBullet4 : public Bullet {
public:
    explicit WoodBullet4(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
    void OnExplode(Enemy* enemy) override;
};
#endif // WOODBULLET_HPP

