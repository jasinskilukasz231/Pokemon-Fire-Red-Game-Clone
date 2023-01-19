#include "PokemonMenu.h"

void PokemonMenu::initSprite(Texture* background, Texture* emptyBoard, Texture* cancelButton)
{
	this->background_sprite.setTexture(*background);
	this->background_sprite.setPosition(-400.f, -300.f);

	this->cancelButton_sprite.setTexture(*cancelButton);
	this->cancelButton_sprite.setPosition(150.f, 220.f);
	this->cancelButton_sprite.setTextureRect(IntRect(0.f, 0.f, 232.5f, 68.f));

	for (size_t i = 0; i < 5; i++)
	{
		this->emptySlots.push_back(Sprite());
		this->emptySlots[i].setTexture(*emptyBoard);
		this->emptySlots[i].setPosition(-230.f, -290.f + (i * 100.f));
		this->emptySlots[i].setScale(0.78f, 1.f);
	}
}

PokemonMenu::PokemonMenu(Texture* background, Texture* emptyBoard, Texture* cancelButton)
{
	this->initSprite(background, emptyBoard, cancelButton);
}

void PokemonMenu::Render(RenderTarget& target)
{
	target.draw(this->background_sprite);
	target.draw(this->cancelButton_sprite);
	
	if(0>=this->how_mch_empty_slots_spawn)
		target.draw(this->emptySlots[0]);
	if (1 >= this->how_mch_empty_slots_spawn)
		target.draw(this->emptySlots[1]);
	if (2 >= this->how_mch_empty_slots_spawn)
		target.draw(this->emptySlots[2]);
	if (3 >= this->how_mch_empty_slots_spawn)
		target.draw(this->emptySlots[3]);
	if (4 >= this->how_mch_empty_slots_spawn)
		target.draw(this->emptySlots[4]);
}

void PokemonMenu::getData(int pokemons_in_pocket)
{
	this->how_mch_empty_slots_spawn = pokemons_in_pocket;
}

