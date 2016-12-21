#include "../include/obj.hpp"

RightBar::RightBar(Texture &image, unsigned int maxX, int intNEminems, int l_level, int l_p1_life, int l_p2_life) {
	sprite.setTexture(image);
	sprite.scale(SCALE_X, SCALE_Y);

	pos			= maxX * 16;
	nEminems	= intNEminems;
	level		= l_level;
	p1_life		= l_p1_life;
	p2_life		= l_p2_life;
}

void RightBar::draw(RenderWindow &window) {
	unsigned int	j	= 0,
					k	= 0;

	sprite.setPosition(pos * SCALE_X, 0);
	sprite.setTextureRect(IntRect(368, 16, 32, 208));
	window.draw(sprite);
	sprite.setTextureRect(IntRect(320, 192, 9, 9));

	for (int	i	= 0; i < nEminems; ++i)
	{
		sprite.setPosition((pos + 8 + j) * SCALE_X, (8 * SCALE_Y) + k);

		k	+= 8 * SCALE_X;

		if ((i >= 9) && (j == 0))
		{
			j	= 8;
			k	= 0;
		}

		window.draw(sprite);
	}

	sprite.setPosition((pos + 16) * SCALE_X, (128 * SCALE_Y));

	if (p1_life == 3) {
		sprite.setTextureRect(IntRect(352, 183, 9, 9));
	}
	else if (p1_life == 2)
	{
		sprite.setTextureRect(IntRect(344, 183, 9, 9));
	}
	else if (p1_life == 1)
	{
		sprite.setTextureRect(IntRect(336, 183, 9, 9));
	}
	else if (p1_life >= 0)
	{
		sprite.setTextureRect(IntRect(328, 183, 9, 9));
	}

	window.draw(sprite);

	sprite.setPosition((pos + 16) * SCALE_X, (152 * SCALE_Y));

	if (p2_life == 3)
	{
		sprite.setTextureRect(IntRect(352, 183, 9, 9));
	}
	else if (p2_life == 2)
	{
		sprite.setTextureRect(IntRect(344, 183, 9, 9));
	}
	else if (p2_life == 1)
	{
		sprite.setTextureRect(IntRect(336, 183, 9, 9));
	}
	else if (p2_life >= 0)
	{
		sprite.setTextureRect(IntRect(328, 183, 9, 9));
	}

	window.draw(sprite);

}

void RightBar::setEminems(int c) {
	nEminems	= c;
}

int RightBar::getEminems() {
	return nEminems;
}

void RightBar::setP1Life(int c) {
	p1_life	= c;
}

int RightBar::getP1Life() {
	return p1_life;
}

void RightBar::setP2Life(int c) {
	p2_life	= c;
}

int RightBar::getP2Life() {
	return p2_life;
}

void RightBar::setLevel(int c) {
	level	= c;
}

int RightBar::getLevel() {
	return level;
}