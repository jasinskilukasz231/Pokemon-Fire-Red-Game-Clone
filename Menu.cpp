#include "Menu.h"

Menu::Menu(Texture* tex_menu, Texture* tex_pointer, Texture* tex_board)
{
	this->sprite_menu.setTexture(*tex_menu);
	this->sprite_pointer.setTexture(*tex_pointer);
	this->sprite_board.setTexture(*tex_board);

	this->sprite_menu.setScale(0.75f, 0.75f);
	this->sprite_board.setScale(0.7f, 0.37f);

	this->sprite_menu.setPosition({ 0.f,0.f });
	this->sprite_pointer.setPosition({ 0.f,0.f });
	this->sprite_board.setPosition({ 0.f,0.f });
}

void Menu::Render(RenderTarget& target)
{
	target.draw(this->sprite_board);
	target.draw(this->sprite_menu);
	target.draw(this->sprite_pointer);

	//cout << this->sprite_pointer.getPosition().x << " " << this->sprite_pointer.getPosition().y << endl;
}

void Menu::SetMenuPos(Vector2f menu_pos)
{
	this->sprite_menu.setPosition({ menu_pos.x + 18.f, menu_pos.y - 178.f });
	this->sprite_board.setPosition({ menu_pos.x - 250.f, menu_pos.y + 90.f });
	this->sprite_pointer.setPosition({ menu_pos.x + 38.f, menu_pos.y - 160.f });

}

void Menu::setPointerPos(Vector2f pos)
{
	this->sprite_pointer.setPosition(this->sprite_pointer.getPosition().x, this->sprite_pointer.getPosition().y + pos.y);
}
