#ifndef NORMALLITTLEENEMY_HPP
#define NORMALLITTLEENEMY_HPP
#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include <cmath>
#include <random>
#include <string>
#include <vector>
#include <iostream>

#include "AudioHelper.hpp"
#include "Bullet.hpp"
#include "DirtyEffect.hpp"
#include "Enemy.hpp"
#include "ExplosionEffect.hpp"
#include "GameEngine.hpp"
#include "Group.hpp"
#include "IScene.hpp"
#include "LOG.hpp"
#include "PlayScene.hpp"
#include "Turret.hpp"
#include "NormalDiceEnemy.hpp"
#include "PlayScene.hpp"
class Little : public Enemy {
public:
    Little(int x, int y);
};



#endif // NORMALELITTLENEMY_HPP



