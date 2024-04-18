/// <summary>
/// author Pete Lowe May 2019
/// you need to change the above line or lose marks
/// </summary>
#ifndef GAME_HPP
#define GAME_HPP
/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the endif at the bottom
/// </summary>
#include <SFML/Graphics.hpp>

#include "Gregor.h"
#include "SmallApple.h"
#include "BigApple.h"
#include "RottenApple.h"
#include "Settings.h"
#include "Instructions.h"
#include "Upgrades.h"
#include "Menu.h"


class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	
	void setupFontAndText();
	void setupSprite();
	void setupMouseDot();

	void smallAppleCollisions();

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen
	sf::Texture m_logoTexture; // texture used for sfml logo
	sf::Sprite m_logoSprite; // sprite used for sfml logo
	bool m_exitGame; // control exiting game

	// small apple
	
	static const int MAX_SMALL_APPLES = 3;
	SmallApple smallApples[MAX_SMALL_APPLES];
	Gregor gregor;

	// mouse point
	sf::Vector2f m_mouseEndVector;
	sf::CircleShape m_mouseDot;
	sf::Vector2f m_mousePosition;

	void processMouseMove(sf::Event t_event);
	void processMouseReleased();

};

#endif // !GAME_HPP

