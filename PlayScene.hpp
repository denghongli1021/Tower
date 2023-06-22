#ifndef PLAYSCENE_HPP
#define PLAYSCENE_HPP
#include <allegro5/allegro_audio.h>
#include <list>
#include <memory>
#include <utility>
#include <vector>

#include "IScene.hpp"
#include "Point.hpp"

class Turret;
class Tool;
namespace Engine {
	class Group;
	class Image;
	class Label;
	class Sprite;
}  // namespace Engine

class PlayScene final : public Engine::IScene {
private:
	enum TileType {
		TILE_DIRT,
		TILE_FLOOR,
		TILE_OCCUPIED,
		TILE_OCCUPIED2,
		TILE_OCCUPIED3
	};
	ALLEGRO_SAMPLE_ID bgmId;
	std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE> deathBGMInstance;
	std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE> bgmInstance;
	std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE> coinInstance;
protected:
	int lives;
	int money;
	int SpeedMult;
public:
	static bool DebugMode;
	static const std::vector<Engine::Point> directions;
	static const int MapWidth, MapHeight;
	static const int BlockSize;
	static const float DangerTime;
	static const Engine::Point SpawnGridPoint;
	static const Engine::Point EndGridPoint;
	static const std::vector<int> code;
	bool mute;
	int MapId;
	float ticks;
	float deathCountDown;
	int ToolMode;
	// Map tiles.
	Group* TileMapGroup;
	Group* GroundEffectGroup;
	Group* DebugIndicatorGroup;
	Group* BulletGroup;
	Group* TowerGroup;
	Group* EnemyGroup;
	Group* EffectGroup;
	Group* UIGroup;
	Group* ToolGroup;
	Engine::Label* UIMoney;
	Engine::Label* UILives;
	Engine::Image* imgTarget;
	Engine::Sprite* dangerIndicator;
	Turret* preview;
	//Tool* preview2;
	std::vector<std::vector<TileType>> mapState;
	std::vector<std::vector<int>> mapDistance;
	std::list<std::pair<int, float>> enemyWaveData;
	std::list<int> keyStrokes;
	static Engine::Point GetClientSize();
	explicit PlayScene() = default;
	void Initialize() override;
	void Terminate() override;
	void Update(float deltaTime) override;
	void Draw() const override;
	void OnMouseDown(int button, int mx, int my) override;
	void OnMouseMove(int mx, int my) override;
	void OnMouseUp(int button, int mx, int my) override;
	void OnKeyDown(int keyCode) override;
	void Hit();
	int GetMoney() const;
	void EarnMoney(int money);
	void ReadMap();
	void ReadEnemyWave();
	void ConstructUI();
	void ConstructButton(int id, std::string sprite, int price);
	void UIBtnClicked(int id);
	bool CheckSpaceValid(int x, int y);
	bool CheckSpaceValid2(int x, int y);
	std::vector<std::vector<int>> CalculateBFSDistance();
	// void ModifyReadMapTiles();
};
#endif // PLAYSCENE_HPP
