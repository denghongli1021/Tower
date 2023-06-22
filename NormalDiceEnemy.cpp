#include <string>

#include "NormalDiceEnemy.hpp"


DiceNormalEnemy::DiceNormalEnemy(int x, int y) : Enemy("play/dice-1.png", x, y, 25, 70, 350, 50) {
    // TODO 2 (1/3): You can imitate the 2 files: 'RedNormalEnemy.hpp', 'RedNormalEnemy.cpp' to create a new enemy.
}

DiceNormalEnemy2::DiceNormalEnemy2(int x, int y) : Enemy("play/dice-2.png", x, y, 25, 45, 400, 100) {
}

void DiceNormalEnemy2::OnExplode() {
    getPlayScene()->EffectGroup->AddNewObject(new ExplosionEffect(Position.x, Position.y));
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> distId(1, 3);
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, 20);

    // Compensate the time lost.

    for (int i = 0; i < 10; i++) {
    // Random add 10 dirty effects.
        getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-" + std::to_string(distId(rng)) + ".png", dist(rng), Position.x, Position.y));
    }
    Enemy* enemy;
    getPlayScene()->EnemyGroup->AddNewObject(enemy = new DiceNormalEnemy(Position.x, Position.y));
    enemy->UpdatePath(getPlayScene()->mapDistance);
    enemy->Update(0);
}

