#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

class Npc
{
	Sprite sprite;
	Vector2i tex_size;
	Vector2i player_pos_index;
	Vector2i tex_pos;
	int frame;

	void initSprite(Texture* texture, Vector2f char_pos);
public:
	Npc(int npc_type, Texture* texture, Vector2i tex_size, Vector2f char_pos);
	void Render(RenderTarget& target);
	Vector2i getCharPosIndex();
	void setPos(float pos_x, float pos_y);
	const Sprite getSprite() const;
	void Update(bool move, char walk_dir);


	bool npc_move_right = true;
	bool npc_move_left = false;
	bool npc_move_up = false;
	bool npc_move_down = false;
	bool npc_staying = false;

	int staying_timer = 0;
	int staying_time = 0;

	bool go_right_npc = false;
	bool go_left_npc = false;
	bool go_down_npc = false;
	bool go_up_npc = false;

	int choose_dir_number = 0;
	int frames_npc = 0;
	bool npc_movement_being_done = false;
	int going_the_same_dir_counter = 0;
	int change_dir_after = 100; //if the npc in random movement is walking too many steps in one dir
	
};

