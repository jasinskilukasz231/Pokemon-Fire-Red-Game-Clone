#pragma once
#include <iostream>
#include <map>
#include <random>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Player.h"
#include "Npc.h"
#include "Map.h"
#include "Menu.h"
#include "PokemonMenu.h"

using namespace std;
using namespace sf;

class System
{
	//Window 
	Clock game_clock;
	Time timer;
	unsigned const int win_x = 800;
	unsigned const int win_y = 600;
	RenderWindow* window;
	Event ev;
	//Views
	View* mainView;
	View* pok_menu_view;

	//spawning
	unsigned int index_x = 0;
	unsigned int index_y = 0;

	bool show_menu = false;
	bool set_menu_pos = true;
	int menu_index = 0;

	bool show_pok_menu = false;


	//resources
	map <string, Texture*> textures;

	//objects
	Menu* menu;
	PokemonMenu* pokmenu;
	Player* player;
	vector<Map*> map_obj;
	map<string, char> locations;
	vector<Npc*> npcs;


	void PollEv();

	//updating
	bool go_right_player = false;
	bool go_left_player = false;
	bool go_down_player = false;
	bool go_up_player = false;
	
	Vector2i tex_size;

	void changePlayerPos();
	void changeNpcPos(Npc* obj);
	int frames = 0;
	
	bool player_movement_being_done = false;
	

	void playerControl();
	void NpcRandomMovement(Npc* obj);

	void Update();

	//entering house
	void EnterHouse();
	bool entrance_house_1 = false;
	bool goto_house_1 = false;
	void updateViews();


	//rendering
	void RenderObjects();
	void RenderMap();

	void initResources();
	void initTextures();
	void initVariables();
public:
	System();
	~System();
	void Run();

};

