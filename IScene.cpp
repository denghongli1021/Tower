#include <allegro5/allegro.h>
#include <iostream>
#include "IScene.hpp"


namespace Engine {
	void IScene::Terminate() {
		Clear();
	}
	void IScene::Draw() const {
		al_clear_to_color(al_map_rgb(0, 0, 0));
		// Group::Draw() ;
		//std::cout << "Group::Draw() \n";
		Group::Draw();
	}
}
