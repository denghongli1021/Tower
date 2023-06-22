#include "Bullet.hpp"
#include "Collider.hpp"
#include "Enemy.hpp"
#include "GameEngine.hpp"
#include "Group.hpp"
#include "IObject.hpp"
#include "IScene.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Sprite.hpp"
#include "Turret.hpp"


PlayScene* Bullet::getPlayScene() {
	return dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetActiveScene());
}
void Bullet::OnExplode(Enemy* enemy) {
//    if (bulletcount) {
//        bulletcount--;
//    }
    //bulletcount--;
}
Bullet::Bullet(std::string img, float speed, float damage, Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent) :
	Sprite(img, position.x, position.y), speed(speed), damage(damage), parent(parent) {
	Velocity = forwardDirection.Normalize() * speed;
	Rotation = rotation;
	CollisionRadius = 4;
}
void Bullet::Update(float deltaTime) {
	Sprite::Update(deltaTime);
	//std::cout << "Updating\n" ;
    if (damage == 150) {
        if (parent) {
            // 更新子弹的旋轉角度，使其與炮台保持一致
            Rotation += deltaTime * 1;
            Engine::Point relativePosition = parent->Position + parent->Size / 2 + Engine::Point(std::cos(Rotation), -std::sin(Rotation)) * 200;
            Position = relativePosition - Size / 2;
            //std::cout << "Bullecount : " << this->parent->bulletcount << "\n" ;
        }
    }
	PlayScene* scene = getPlayScene();
	// Can be improved by Spatial Hash, Quad Tree, ...
	// However simply loop through all enemies is enough for this program.
	//int check = 0;
	for (auto& it : scene->EnemyGroup->GetObjects()) {
		Enemy* enemy = dynamic_cast<Enemy*>(it);
		if (!enemy->Visible)
			continue;
		if (Engine::Collider::IsCircleOverlap(Position, CollisionRadius, enemy->Position, enemy->CollisionRadius)) {
			//OnExplode(enemy);
			enemy->Hit(damage);
			getPlayScene()->BulletGroup->RemoveObject(objectIterator);
			if (this->parent->price == 80) {
                this->parent->bulletcount--;
                //std::cout << "after -- bulletcount : " << this->parent->bulletcount << "\n" ;
			}
			break;
		}
	}
//	if (check) {
//        this->parent->bulletcount--;
//	}

	// Check if out of boundary.
	if (!Engine::Collider::IsRectOverlap(Position - Size / 2, Position + Size / 2, Engine::Point(0, 0), PlayScene::GetClientSize()) && damage != 150)
		getPlayScene()->BulletGroup->RemoveObject(objectIterator);
}
