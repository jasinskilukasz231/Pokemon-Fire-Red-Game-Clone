#include "Player.h"

void Player::initSprite(Texture* texture, Vector2f player_pos)
{
	this->sprite.setPosition(player_pos);
	this->sprite.setTexture(*texture);
	this->sprite.setTextureRect(IntRect(this->tex_pos.x, this->tex_pos.y, this->tex_size.x, this->tex_size.y));

}
Player::Player(Texture* texture, Vector2i tex_size, Vector2f player_pos)
{
	//init variables
	this->tex_pos.x = 0;
	this->tex_pos.y = 0;

	this->player_pos_index.x = 0;
	this->player_pos_index.y = 0;

	this->frame = 0;

	this->tex_size = tex_size;

	this->initSprite(texture, player_pos);
}
void Player::Render(RenderTarget& target)
{
	target.draw(this->sprite);
}
void Player::setPosition(float pos_x, float pos_y)
{
	this->sprite.setPosition(pos_x, pos_y);
}
void Player::PlayerMovementAnimation(bool move, char dir)
{
	//4 - down 3 - up 2 - left 1 - right
	if (move == true)
	{
		this->frame++;
		if (this->frame >= 10) this->frame = 0;

		switch (dir)
		{
		case '1':
			if (this->frame % 2 == 0)
			{
				this->tex_pos.x = this->tex_size.x * 2; 
				this->tex_pos.y = 0;
			}
			else
			{
				this->tex_pos.x = this->tex_size.x * 3;
				this->tex_pos.y = 0;
			}
			break;
		case '2':
			if (this->frame % 2 == 0)this->tex_pos.y = this->tex_size.y;
			else
			{
					this->tex_pos.x = this->tex_size.x;
					this->tex_pos.y = this->tex_size.y;
			}
			break;
		case '3':
			if (this->frame % 2 == 0)
			{
				this->tex_pos.x = this->tex_size.x * 2;
				this->tex_pos.y = this->tex_size.y;
			}
			else
			{
				this->tex_pos.x = this->tex_size.x * 3;
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
				this->tex_pos.x = 0;
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
const Sprite Player::getSprite() const
{
	return this->sprite;
}
Vector2i Player::getPlayerPosIndex()
{
	this->player_pos_index.x = int(this->sprite.getPosition().x / this->tex_size.x);
	this->player_pos_index.y = int(this->sprite.getPosition().y / this->tex_size.y);

	return this->player_pos_index;
}

