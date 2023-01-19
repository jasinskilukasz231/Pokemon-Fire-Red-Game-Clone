#include "Pokemon.h"


void Pokemon::initSprite(string name, int lvl, Texture* tex)
{
	this->sprite.setTexture(*tex);

}
void Pokemon::lvlUp()
{
	int exp=0;

	if (this->current_exp >= this->next_lvl_exp)
	{
		exp = this->current_exp - this->next_lvl_exp;
		this->current_exp = exp;

		this->BoostStats();
	}
}
void Pokemon::BoostStats()
{

}
Pokemon::Pokemon(string name, int lvl, int hp, int energy, Texture* tex)
{
	this->initSprite(name, lvl, tex);

}
void Pokemon::AddSkill(string name, char effect)
{
	this->skills[name] = effect;
}

void Pokemon::AddExp(int value)
{
	this->current_exp += value;
}
void Pokemon::Render(RenderTarget& target)
{
	target.draw(this->sprite);
}
void Pokemon::Update()
{
	this->lvlUp();

}

const Sprite Pokemon::getSprite() const
{
	return this->sprite;
}
