#include "DrawMap.h"

DrawMap::DrawMap(int pos_x, int pos_y, Texture* tex, bool change_origin, float or_x, float or_y,
	bool setRect, int rect_index_x, int rect_index_y)
{
	this->sprite.setTexture(*tex);
	this->sprite.setPosition(pos_x, pos_y);

	if (change_origin == true)
	{
		this->sprite.setOrigin({ or_x, or_y });
	}

	if (setRect == true)
	{
		this->sprite.setTextureRect(IntRect(this->tex_size_x * rect_index_x, this->tex_size_y * rect_index_y, 
			this->tex_size_x, this->tex_size_y));
	}

}

void DrawMap::Render(RenderTarget& target)
{
	target.draw(this->sprite);
}
