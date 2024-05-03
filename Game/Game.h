#pragma once
#include "Player.h"
#include "Enemies.h"
#include "Bullets.h"
#include "Text.h"
#include <SFML/Graphics.hpp>

class Game
{
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;
	bool endGame;

	void initVariables();
	void initWindow();

	//Calling classes
	Player player;
	Enemies enemy;
    Bullets bullets;
	Text text;

public:
	Game();
	virtual ~Game();

	void pollEvents();
	const bool isRunning() const;

	void update();
	void render();
};

