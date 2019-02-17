#include <iostream>
#include <string>
#include <sstream>
#include "Task.h"

using namespace sf;
using namespace std;

int main() {

	RenderWindow window(VideoMode(600, 400), "SFMLworks");

	Texture tileSet;
	tileSet.loadFromFile("res/TailMap4.png");
	Sprite tile(tileSet);

	Texture t;
	t.loadFromFile("res/proger.png");

	float currentFrame = 0;

	Font font;
	font.loadFromFile("res/CyrilicOld.TTF");
	Text text("", font, 20);
	text.setColor(Color::Red);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	Text text2("", font, 20);
	text2.setColor(Color::Red);
	text2.setStyle(sf::Text::Bold | sf::Text::Underlined);

	Player player(t);

	Clock clock;

	while (window.isOpen()) {

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		Event event;

		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}

		if (!onTask && !endGame) {
			if (Keyboard::isKeyPressed(Keyboard::Left)) {
				player.dx = -0.1;
			}
			if (Keyboard::isKeyPressed(Keyboard::Right)) {
				player.dx = 0.1;
			}
			if (Keyboard::isKeyPressed(Keyboard::Up)) {
				if (player.onGround) {
					player.dy = -0.36;
					player.onGround = false;
				}
			}
		}

		player.Update(time);

		if (player.rect.left > 300)
			player.offsetX = player.rect.left - 300;

		player.offsetY = player.rect.top - 200;

		window.clear(Color::White);

		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++) {
				if (TileMap[i][j] == 'B')
					tile.setTextureRect(IntRect(490, 180, 32, 32));
				if (TileMap[i][j] == 'C')
					tile.setTextureRect(IntRect(19, 9, 32 * 3, 32 * 3));
				if (TileMap[i][j] == 'P')
					tile.setTextureRect(IntRect(117, 6, 139, 74));
				if (TileMap[i][j] == 'N')
					tile.setTextureRect(IntRect(580, 49, 62, 96));
				if (TileMap[i][j] == 'W')
					tile.setTextureRect(IntRect(13, 150, 192, 141));
				if (TileMap[i][j] == 'S')
					tile.setTextureRect(IntRect(590, 170, 138, 64));
				if (TileMap[i][j] == 'A')
					tile.setTextureRect(IntRect(510, 280, 61, 96));
				if (TileMap[i][j] == 'O')
					tile.setTextureRect(IntRect(610, 280, 133, 64));
				if (TileMap[i][j] == 'a' || TileMap[i][j] == 'c' || TileMap[i][j] == 'd' || TileMap[i][j] == 'e' || TileMap[i][j] == 'f')
					tile.setTextureRect(IntRect(749, 0, 32, 160));
				if (TileMap[i][j] == 'o')
					tile.setTextureRect(IntRect(650, 1, 86, 160));
				if (TileMap[i][j] == 'H')
					tile.setTextureRect(IntRect(489, 10, 71, 128));
				if (TileMap[i][j] == 'T')
					tile.setTextureRect(IntRect(261, 20, 201, 128));
				if (TileMap[i][j] == 'I')
					tile.setTextureRect(IntRect(89, 330, 88, 96));
				if ((int)TileMap[i][j] - '0' >= 0 && (int)TileMap[i][j] - '0' <= 9)
					tile.setTextureRect(IntRect(258, 176, 62, 64));
				if (TileMap[i][j] == ' ' || TileMap[i][j] == 'b')
					continue;

				tile.setPosition(j * 32 - player.offsetX, i * 32 - player.offsetY);
				window.draw(tile);
			}

		window.draw(player.sprite);
		std::ostringstream playerScoreString;
		playerScoreString << player.health;
		text.setString("Salary:" + playerScoreString.str());
		text.setPosition(0, 360);
		window.draw(text);

		if (onTask) {
			Task ts(player.idTask);
			window.draw(ts.spriteTask);
			ts.ResTask(player.idTask);
		}

		if (ifDamage) {
			ifDamage = false;
			player.health += damage;
			damage = 0;
		}

		if (endGame) {
			text.setString("Your Salary:" + playerScoreString.str());
			text.setPosition(50, 50);
			window.draw(text);
		}

		window.display();
	}

	return 0;
}