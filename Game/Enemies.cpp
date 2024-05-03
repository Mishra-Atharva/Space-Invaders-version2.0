#include "Enemies.h"
#include <iostream>

void Enemies::initVariables()
{
	this->maxEnemies = 10;
	this->spawnTimerMax = 1000.f;
	this->spawnTimer = this->spawnTimerMax;
	this->moveSpeed = 5.f;
}

void Enemies::initEnemy()
{
	sf::Color color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
	this->enemy.setSize(sf::Vector2f(40.f, 40.f));
	this->enemy.setFillColor(color);
	this->enemy.setPosition(static_cast<float>((rand() % 559) + 1), 0.f);
}

Enemies::Enemies()
{
	this->initVariables();
}

Enemies::~Enemies()
{
}

void Enemies::spawnEnemy()
{
	if (this->spawnTimer < this->spawnTimerMax)
	{
		this->spawnTimer += 10.f;
	}
	else
	{
		if (this->enemies.size() < this->maxEnemies)
		{
			this->initEnemy();
			this->enemies.push_back(this->enemy);
			this->spawnTimer = 0.f;
		}
	}
}

void Enemies::moveCollision(const sf::RenderWindow& window, int& health)
{
	for (size_t i = 0; i < this->enemies.size(); i++)
	{
		this->enemies[i].move(0.f, this->moveSpeed);

		if (this->enemies[i].getPosition().y > window.getSize().y)
		{
			this->remove(i);
			health--;
		}
	}
}

void Enemies::remove(int x)
{
	this->enemies.erase(this->enemies.begin() + x);
	std::cout << "Removed" << std::endl;
}

const std::vector<sf::RectangleShape>& Enemies::getShape() const
{
	// TODO: insert return statement here
	return this->enemies;
}

void Enemies::update(const sf::RenderWindow& window, int& health)
{
	this->moveCollision(window, health);
	this->spawnEnemy();
}

void Enemies::render(sf::RenderWindow* window)
{
	for (auto& e : this->enemies)
	{
		window->draw(e);
	}
}
