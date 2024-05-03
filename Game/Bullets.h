#pragma once
#include <SFML/Graphics.hpp>
#include "Enemies.h"

class Bullets
{
private:
	sf::RectangleShape bullet;
	std::vector<sf::RectangleShape> bullets;

	int maxBullet;
	int bulletSpeed;

	void initVariables();
	void initBullet(float x, float y);

public:
	int points;
	
	Bullets();
	virtual ~Bullets();

	void spawnBullets(float x, float y);
	void bulletMove();
	void enemyCollision(Enemies& enemies);
	void remove(int x);

	void update(Enemies& enemies);
	void render(sf::RenderWindow* window);
};

