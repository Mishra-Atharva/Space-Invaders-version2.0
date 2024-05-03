#include "Player.h"
#include "Bullets.h"
#include <iostream>

void Player::initVariables()
{
	this->health = 3;
	this->moveSpeed = 5.f;
}

void Player::initPlayer()
{
	this->player.setSize(sf::Vector2f(20.f, 20.f));
	this->player.setFillColor(sf::Color::White);
	this->player.setPosition(10.f, 10.f);
	this->player.setPosition(static_cast<float>(600/2), static_cast<float>(500 - this->player.getSize().y) - 10.f);
}

Player::Player()
{
	this->initVariables();
	this->initPlayer();
}

Player::~Player()
{
}

void Player::playerInput(const sf::RenderWindow& window, Bullets& bullets)
{
	static bool fired = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && this->player.getPosition().x > 0)
	{
		this->player.move(-this->moveSpeed, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && this->player.getPosition().x < (window.getSize().x - this->player.getSize().x))
	{
		this->player.move(this->moveSpeed, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !fired)
	{
		bullets.spawnBullets(this->player.getPosition().x, this->player.getPosition().y);
		std::cout << "Fire!" << std::endl;
	}

	fired = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
}

void Player::update(const sf::RenderWindow& window, Bullets& bullets)
{
	this->playerInput(window, bullets);
}

void Player::render(sf::RenderWindow* window)
{
	window->draw(this->player);
}
