#include "Bullets.h"
#include "SFML/Graphics/Rect.hpp"
#include <iostream>
#include <vector>

void Bullets::initVariables()
{
	this->maxBullet = 10;
	this->bulletSpeed = 15.f;
	this->points = 0;
}

void Bullets::initBullet(float x, float y)
{
	this->bullet.setSize(sf::Vector2f(5.f, 10.f));
	this->bullet.setFillColor(sf::Color::Red);
	this->bullet.setPosition((x + this->bullet.getSize().x)+3, y + this->bullet.getSize().y);
}

Bullets::Bullets()
{
	this->initVariables();
}

Bullets::~Bullets()
{
}

void Bullets::spawnBullets(float x, float y)
{
	if (this->bullets.size() < this->maxBullet)
	{
		this->initBullet(x, y);
		this->bullets.push_back(this->bullet);
	}
}

void Bullets::bulletMove()
{
	for (size_t x = 0; x < this->bullets.size(); x++)
	{
		this->bullets[x].move(0.f, -this->bulletSpeed);

		if (this->bullets[x].getPosition().y < 0)
		{
			this->remove(x);
		}
	}
}

void Bullets::enemyCollision(Enemies& enemies)
{
	for (size_t y = 0; y < this->bullets.size(); y++)
	{
		for (size_t x = 0; x < enemies.getShape().size(); x++)
		{
			if (this->bullets[y].getGlobalBounds().intersects(enemies.getShape()[x].getGlobalBounds()))
			{
				enemies.remove(x);
				this->remove(y);
				this->points++;
				break;
			}
		}
	}
}

void Bullets::remove(int x)
{
	this->bullets.erase(this->bullets.begin() + x);
}

void Bullets::update(Enemies& enemies)
{
	this->bulletMove();
    this->enemyCollision(enemies);
}

void Bullets::render(sf::RenderWindow* window)
{
	for (auto i : this->bullets)
	{
		window->draw(i);
	}
}
