#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

class Player
{
	Sprite sprite;
	Vector2i tex_size;
	Vector2i player_pos_index;
	Vector2i tex_pos;
	int frame;

	void initSprite(Texture* texture, Vector2f player_pos);
public:
	Player(Texture* texture, Vector2i tex_size, Vector2f player_pos);
	~Player() = default;
	void Render(RenderTarget& target);
	void setPosition(float pos_x, float pos_y);
	void PlayerMovementAnimation(bool move, char dir);
	const Sprite getSprite() const;
	Vector2i getPlayerPosIndex();
};

