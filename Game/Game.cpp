#include "Game.h"

void Game::initVariables()
{
	this->endGame = false;
}

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(600, 500);
	this->window = new sf::RenderWindow(this->videoMode, "Space Invaders", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

Game::Game() : player(), enemy(), text(), bullets()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape || this->endGame)
			{
				this->window->close();
				break;
			}
		}
	}
}

const bool Game::isRunning() const
{
	return this->window->isOpen();
}

void Game::update()
{
	this->pollEvents();
	//updating classes
	if (!endGame)
	{
		this->player.update(*this->window, this->bullets);
		this->enemy.update(*this->window, this->player.health);
		this->bullets.update(this->enemy);
	}
	this->text.update(this->bullets.points, this->player.health, this->endGame);
}

void Game::render()
{
	this->window->clear();

	//rendering classes
	if (!endGame)
	{
		this->enemy.render(this->window);
		this->player.render(this->window);
		this->bullets.render(this->window);
	}
	this->text.render(this->window);
	this->window->display();
}
