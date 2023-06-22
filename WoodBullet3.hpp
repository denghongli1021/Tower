#ifndef WOODBULLET3_HPP
#define WOODBULLET3_HPP
#include "Bullet.hpp"

class Enemy;
class Turret;
namespace Engine {
    struct Point;
}  // namespace Engine

class WoodBullet3 : public Bullet {
public:
    explicit WoodBullet3(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
    void OnExplode(Enemy* enemy) override;
};
#endif // WOODBULLET_HPP


