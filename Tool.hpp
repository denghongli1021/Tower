#ifndef TOOL_HPP
#define TOOL_HPP
#include <allegro5/base.h>
#include <list>
#include <string>

#include "Sprite.hpp"

class Enemy;
class PlayScene;

class Tool: public Engine::Sprite {
protected:
    float coolDown;
    float reload = 0;
    float rotateRadian = 2 * ALLEGRO_PI;
    Sprite imgTool;
    PlayScene* getPlayScene();
    // Reference: Design Patterns - Factory Method.
    virtual void CreateBullet() = 0;

public:
    int price;
    bool Enabled = true;
    bool Preview = false;
    Tool(std::string imgTool, float x, float y,int price, float coolDown);
    void Update(float deltaTime) override;
    void Draw() const override;
	int GetPrice(int id) const;
};
#endif // TOOL_HPP

