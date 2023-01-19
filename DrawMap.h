#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

class DrawMap //CLASS ONLY FOR DRAWING SPRITES
{
	const float tex_size_x = 40.f;
	const float tex_size_y = 32.f;

	Sprite sprite;
public:
	DrawMap(int pos_x, int pos_y, Texture* tex, bool change_origin, float or_x, float or_y,
		bool setRect, int rect_index_x, int rect_index_y);
	void Render(RenderTarget& target);
};

