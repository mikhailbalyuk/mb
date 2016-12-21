#include "../include/configurator.h"
#include "../include/obj.hpp"

GameMap::GameMap(Texture &image) {
	sprite.setTexture(image);
	sprite.scale(SCALE_X, SCALE_Y);
	maxX	= maxY	= grass_num	= 0;
}

GameMap::~GameMap() {
	for (unsigned int	i	= 0; i <= maxX; ++i)
		delete [] p_map[i];

	for (unsigned int	i	= 0; i <= grass_num; ++i)
		delete [] g_map[i];

	delete [] p_map;
	delete [] g_map;
}

bool GameMap::loadMap(std::string path) {
	std::string	temp_map;

	unsigned int	count		= 0;

	maxX			= atoi(configurator(path, "max_x", "", false).c_str());
	maxY			= atoi(configurator(path, "max_y", "", false).c_str());
	next_level_path	= configurator(path, "next_level", "", false);
	temp_map		= configurator(path, "map", "", false);

	p_map	= new char* [maxX + 1];
		for (unsigned int	i	= 0; i <= maxX; ++i)
			p_map[i] = new char [maxY + 1];

	for (unsigned int	j	= 0; j < maxY; ++j)				// Загрузка карты в массив
		for (unsigned int	i	= 0; i < maxX; ++i)
		{
			while ((temp_map[count] < 'a') || (temp_map[count] > 'z'))	// Чтобы не влезла разная кака на карту
				count++;

			if (temp_map[count] == 'g')						// Подсчёт кол-ва травы
				grass_num++;

			p_map[i][j]	= temp_map[count];
			count++;
		}

	g_map	= new unsigned int* [grass_num + 1];
		for (unsigned int	i	= 0; i <= grass_num; ++i)
			g_map[i] = new unsigned int [2];

	count	= 0;

	for (unsigned int	i	= 0; i < maxX; ++i)
		for (unsigned int	j	= 0; j < maxY; ++j)
			if (p_map[i][j] == 'g')	{
				g_map[count][0]	= i;
				g_map[count][1]	= j;
				count++;
			}

	return true;
}

char GameMap::getElement(unsigned int x, unsigned int y) {
	return p_map[x][y];
}

void GameMap::draw(RenderWindow &window) {
	window.clear(Color(0,0,0));

	for (unsigned int	j	= 0; j < maxY; ++j) {
		for (unsigned int	i	= 0; i < maxX; ++i) {
			if (p_map[i][j] == 'w')							// Кирпичная стена
				sprite.setTextureRect(IntRect(256, 0, 16, 16));
			else if (p_map[i][j] == 'a')					// Бронь
				sprite.setTextureRect(IntRect(256, 16, 16, 16));
			else if (p_map[i][j] == 'v')					// Вода
				sprite.setTextureRect(IntRect(256, 32, 16, 16));
			else if (p_map[i][j] == 'i')					// Лёд, я полагаю...
				sprite.setTextureRect(IntRect(288, 32, 16, 16));
			else if (p_map[i][j] == 'e')					// Орёл
				sprite.setTextureRect(IntRect(304, 32, 16, 16));
			else
				continue;

			sprite.setPosition(i * (16 * SCALE_X), j * (16 * SCALE_Y)) ;
			window.draw(sprite);
		}
	}
}

void GameMap::drawGrass(RenderWindow &window) {
	sprite.setTextureRect(IntRect(272, 32, 16, 16));

	for (unsigned int	i	= 0; i < grass_num; ++i) {
		sprite.setPosition(g_map[i][0] * (16 * SCALE_X), g_map[i][1] * (16 * SCALE_Y)) ; 
		window.draw(sprite);
	}
}

unsigned int GameMap::getMaxX() {
	return maxX;
}

unsigned int GameMap::getMaxY() {
	return maxY;
}

void GameMap::setElement(char l_char, unsigned int x, unsigned int y) {
	p_map[x][y]	= l_char;
}