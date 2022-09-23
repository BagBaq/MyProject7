#include <box2d/box2d.h>
#include "Source.h"

int main()
{
	sf::Texture BackgroundTexture, PlayerTexture;
	sf::Sprite BackgroundSprite, PlayerSprite;

	World *gameWorld = new World();
	Player player = Player(gameWorld->getb2World(), gameWorld->getRes(0).w_playerTexture);
	Level level1(gameWorld->getb2World(), &player, gameWorld->getRes(0).w_backgroundTexture);

	while (s_gameWindow.isOpen())
	{
		gameWorld->getb2World()->Step(1.0f / 180.0f, 8, 3);

		sf::Event events;

		while (s_gameWindow.pollEvent(events))
		{
			if (events.type == sf::Event::Closed) s_gameWindow.close();
		}
		s_gameWindow.clear();
		level1.Update();
		level1.Draw();
		s_gameWindow.display();
	}
	delete gameWorld;
	return 0;
}