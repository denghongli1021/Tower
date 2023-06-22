// [main.cpp]
// this template is provided for the 2D tower defense game.
// Program entry point.
// Returns program exit code.

#include "GameEngine.hpp"
#include "LOG.hpp"
#include "LoseScene.hpp"
#include "PlayScene.hpp"
#include "StartScene.hpp"
#include "StageSelectScene.hpp"
#include "WinScene.hpp"

int main(int argc, char **argv) {
	Engine::LOG::SetConfig(true);
	Engine::GameEngine& game = Engine::GameEngine::GetInstance();
	game.AddNewScene("stage-select", new StageSelectScene());
	game.AddNewScene("play", new PlayScene());
	game.AddNewScene("lose", new LoseScene());
	game.AddNewScene("win", new WinScene());
    game.AddNewScene("start-scene", new StartScene());
	game.Start("start-scene", 60, 1600, 832);
	return 0;
}

/*
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
int main(int argc, char** argv) {
    al_init();
    al_init_font_addon();
    ALLEGRO_DISPLAY* display = al_create_display(800, 600);
    ALLEGRO_FONT* font = al_create_builtin_font();
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_text(font, al_map_rgb(255, 255, 255), 400, 300, ALLEGRO_ALIGN_CENTER, "Welcome to Allegro!");
    al_flip_display();
    al_rest(5.0);
    al_destroy_font(font);
    al_destroy_display(display);
    return 0;
}
*/

