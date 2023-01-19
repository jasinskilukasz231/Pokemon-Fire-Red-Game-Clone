#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

class PokemonMenu
{
	Sprite background_sprite;
	Sprite cancelButton_sprite;
	vector<Sprite> emptySlots;

	int how_mch_empty_slots_spawn = 0;

	void initSprite(Texture* background, Texture* emptyBoard, Texture* cancelButton);
public:
	PokemonMenu(Texture* background, Texture* emptyBoard, Texture* cancelButton);
	void Render(RenderTarget& target);
	void getData(int pokemons_in_pocket);

};

