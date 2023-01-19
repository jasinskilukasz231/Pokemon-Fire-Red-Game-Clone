#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

class Menu
{
	Sprite sprite_menu;
	Sprite sprite_board;
	Sprite sprite_pointer;
public:
	Menu(Texture* tex_menu, Texture* tex_pointer, Texture* tex_board);
	void Render(RenderTarget& target);
	void SetMenuPos(Vector2f menu_pos);
	void setPointerPos(Vector2f pos);
};

