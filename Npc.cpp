#include "Npc.h"

Npc::Npc(int npc_type, Texture* texture, Vector2i tex_size, Vector2f char_pos)
{
	//init variables
	this->tex_pos.x = 0;
	this->tex_pos.y = 0;

	this->player_pos_index.x = 0;
	this->player_pos_index.y = 0;

	this->frame = 0;

	this->tex_size = tex_size;

	this->initSprite(texture, char_pos);
}

void Npc::Render(RenderTarget& target)
{
	target.draw(this->sprite);
}

Vector2i Npc::getCharPosIndex()
{
	this->player_pos_index.x = int(this->sprite.getPosition().x / this->tex_size.x);
	this->player_pos_index.y = int(this->sprite.getPosition().y / this->tex_size.y);

	return this->player_pos_index;
}

void Npc::initSprite(Texture* texture, Vector2f char_pos)
{
	this->sprite.setTexture(*texture);
	this->sprite.setPosition(char_pos);
	this->sprite.setTextureRect(IntRect(this->tex_pos.x, this->tex_pos.y, this->tex_size.x, this->tex_size.y));
}

void Npc::setPos(float pos_x, float pos_y)
{
	this->sprite.setPosition(pos_x, pos_y);
}

const Sprite Npc::getSprite() const
{
	return this->sprite;
}

void Npc::Update(bool move, char walk_dir)
{
	//4 - down 3 - up 2 - left 1 - right
	if (move == true)
	{
		this->frame++;

		switch (walk_dir)
		{
		case '1':
			if (this->frame % 2 == 0)
			{
				this->tex_pos.x = this->tex_size.x * 2;
				this->tex_pos.y = this->tex_size.y * 2;
			}
			else
			{
				this->tex_pos.y = this->tex_size.y * 3;
				this->tex_pos.x = 0;
			}
			break;
		case '2':
			if (this->frame % 2 == 0)
			{
				this->tex_pos.y = this->tex_size.y * 2;
				this->tex_pos.x = 0;
			}
			else
			{
				this->tex_pos.y = this->tex_size.y * 2;
				this->tex_pos.x = this->tex_size.x;
			}
			break;
		case '3':
			if (this->frame % 2 == 0)
			{
				this->tex_pos.x = this->tex_size.x;
				this->tex_pos.y = this->tex_size.y;
			}
			else
			{
				this->tex_pos.x = this->tex_size.x * 2;
				this->tex_pos.y = this->tex_size.y;
			}

			break;
		case '4':
			if (this->frame % 2 == 0)
			{
				this->tex_pos.x = this->tex_size.x;
				this->tex_pos.y = 0;
			}
			else
			{
				this->tex_pos.x = this->tex_size.x * 2;
				this->tex_pos.y = 0;
			}
			break;
		}
	}
	else
	{
		this->tex_pos.x = 0;
		this->tex_pos.y = 0;
		this->frame = 0;
	}

	this->sprite.setTextureRect(IntRect(this->tex_pos.x, this->tex_pos.y, this->tex_size.x, this->tex_size.y));
}
