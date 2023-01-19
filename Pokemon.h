#pragma once
#include <iostream>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

class Pokemon
{
	Sprite sprite;

	string name;
	int lvl;
	int hp;
	int energy;
	int attack;
	int next_lvl_exp;
	int current_exp;

	//
	int poison_deff;
	int fire_deff;
	int sleep_deff;
	int dizzle_deff;
	int deffence;
	//
	map <string, char> skills; //skill with name and skill effect


	void initSprite(string name, int lvl, Texture* tex);
	void lvlUp();
	void BoostStats();
public:
	Pokemon(string name, int lvl, int hp, int energy, Texture* tex);
	void AddSkill(string name, char effect);
	void AddExp(int value);
	void Render(RenderTarget& target);
	void Update();

	const Sprite getSprite() const;

};

