#include "Text.h"
#include <sstream>

void Text::initVaraibles()
{
	this->font.loadFromFile("Fonts/Shogie.otf");
	this->ui.setCharacterSize(24);
	this->ui.setFillColor(sf::Color::White);
	this->ui.setFont(this->font);
	this->ui.setPosition(10.f, 10.f);

}

void Text::initText(int points, int health)
{
	std::stringstream ss;
	ss << "Health: " << health << "\nPoints: " << points;
	this->ui.setString(ss.str());
}

Text::Text()
{
	this->initVaraibles();
}

Text::~Text()
{
}

void Text::textInfo(int points, int health, bool& endGame)
{
	if (health == 0)
	{
		std::stringstream ss;
		ss << "You Lose\nPoints: " << points;
		this->ui.setString(ss.str());
		this->ui.setPosition(250.f, 200.f);
		endGame = true;
	}
	else if (health > 0)
	{
		this->initText(points, health);
	}
}

void Text::update(int points, int health, bool& endGame)
{
	this->textInfo(points, health, endGame);
}

void Text::render(sf::RenderWindow* window)
{
	window->draw(this->ui);
}
