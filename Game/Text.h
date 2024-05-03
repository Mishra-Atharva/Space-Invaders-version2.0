#pragma once
#include <SFML/Graphics.hpp>

class Text
{
private:
	sf::Font font;
	sf::Text ui;

	void initVaraibles();
	void initText(int points, int health);

public:
	Text();
	virtual ~Text();

	void textInfo(int points, int health, bool& endGame);

	void update(int points, int health, bool& endGame);
	void render(sf::RenderWindow* window);
};

