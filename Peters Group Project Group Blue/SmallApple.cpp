#include "SmallApple.h"
#include <iostream>

SmallApple::SmallApple()
{
	loadSmallApple();
}

void SmallApple::loadSmallApple()
{
	if (!m_texture.loadFromFile("ASSETS\\IMAGES\\smallApple.png"))
	{
		std::cout << "problem loading small apple texture" << std::endl;
	}

	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(sf::Vector2f(m_texture.getSize().x * m_scale / 2,
									m_texture.getSize().y * m_scale / 2)); // origin in the centre of apple
	std::cout << "Origin x: " << m_sprite.getOrigin().x << " y:" << m_sprite.getOrigin().y << std::endl;
	m_sprite.setPosition(m_position);
	m_sprite.setScale(m_scale, m_scale);
}

sf::Sprite SmallApple::getSprite()
{
	return m_sprite;
}

void SmallApple::spawn()
{
		int side = rand() % 4;
		float xRespawn = 0.0f;
		float yRespawn = 0.0f;

		switch (side)
		{
		case NORTH_SMALL_APPLE: // above screen
		{
			yRespawn = 0 - m_texture.getSize().y * m_scale / 2; // height of apple
			xRespawn = static_cast<float>(rand() % static_cast<int>(SCREEN_WIDTH_SMALL_APPLE)); // random position on x axis
			break;
		}
		case SOUTH_SMALL_APPLE:
		{
			yRespawn = SCREEN_HEIGHT_SMALL_APPLE + m_texture.getSize().y * m_scale / 2;
			xRespawn = static_cast<float>(rand() % static_cast<int>(SCREEN_WIDTH_SMALL_APPLE));
			break;
		}
		case EAST_SMALL_APPLE:
		{
			xRespawn = SCREEN_WIDTH_SMALL_APPLE + m_texture.getSize().x * m_scale / 2;
			yRespawn = static_cast<float>(rand() % static_cast<int>(SCREEN_HEIGHT_SMALL_APPLE));
			break;
		}
		case WEST_SMALL_APPLE:
		{
			xRespawn = 0 - m_texture.getSize().x  * m_scale / 2;
			yRespawn = static_cast<float>(rand() % static_cast<int>(SCREEN_HEIGHT_SMALL_APPLE));
			break;
		}
		}

		m_sprite.setPosition(xRespawn, yRespawn);
		std::cout << "apple position set to x:" << xRespawn << " y:" << yRespawn << std::endl;

}