#pragma once
#include <SFML/Graphics.hpp>

class Enemies
{
private:
	sf::RectangleShape enemy;
	std::vector<sf::RectangleShape> enemies;

	int maxEnemies;
	float spawnTimer;
	float spawnTimerMax;
	int moveSpeed;
	
	void initVariables();
	void initEnemy();

public:
	
	Enemies();
	virtual ~Enemies();

	void spawnEnemy();
	void moveCollision(const sf::RenderWindow& window, int& health);
	void remove(int x);

	const std::vector<sf::RectangleShape>& getShape() const;

	void update(const sf::RenderWindow& window, int& health);
	void render(sf::RenderWindow* window);
};

