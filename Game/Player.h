#pragma once
#include <SFML/Graphics.hpp>
#include "Bullets.h"

class Player
{
private:
	sf::RectangleShape player;
	float moveSpeed;

	void initVariables();
	void initPlayer();

public:
	int health;
	
	Player();
	virtual ~Player();

	void playerInput(const sf::RenderWindow& window, Bullets& bullets);

	void update(const sf::RenderWindow& window, Bullets& bullets);
	void render(sf::RenderWindow* window);
};

