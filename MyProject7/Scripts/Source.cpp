#include <box2d/box2d.h>
#include "Source.h"

int main()
{
	sf::RenderWindow gameWindow(sf::VideoMode(1600, 800), gameWindowTitle, sf::Style::Titlebar);
	gameWindow.setFramerateLimit(gameFramerateLimit);
	sf::View cameraView(sf::Vector2f(0.f, 0.f), sf::Vector2f(1600.f, 800.f));
	b2World box2dWorld = b2World(b2Vec2(0.f, 9.8f));

	Player player(&box2dWorld, &gameWindow);
	ObjectManager objectManager(&box2dWorld, &gameWindow);
	LevelManager levelManager(&objectManager, &gameWindow);
	GUIManager guiManager(&gameWindow);

	levelManager.CreateLevel(1);

	sf::Clock clock;
	float lastTime = 0;
	float fps;

	while (gameWindow.isOpen())
	{
		float currentTime = clock.restart().asSeconds();
		fps = 1.f / currentTime;
		lastTime = currentTime;

		gameWindow.setView(cameraView);
		cameraView.setCenter(player.ReturnPosition());

		box2dWorld.Step(1.0f / 180.0f, 8, 3);

		sf::Event events;

		while (gameWindow.pollEvent(events))
		{
			if (events.type == sf::Event::Closed) gameWindow.close();
			if (events.type == sf::Event::MouseButtonReleased)
			{
				if (events.mouseButton.button == sf::Mouse::Right)
				{
					objectManager.ClickSpawnObject(float(events.mouseButton.x), float(events.mouseButton.y), 32.f, 32.f, sf::Color::Red);
				}
			}
		}
		gameWindow.clear();

		levelManager.Update();
		player.Update(events);
		objectManager.Update();

		gameWindow.setView(gameWindow.getDefaultView());
		guiManager.Update(int(fps));

		gameWindow.display();
	}

	return 1;
}