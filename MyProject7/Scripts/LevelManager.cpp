#include "LevelManager.h"

LevelManager::LevelManager(ObjectManager* objectManager_ref, sf::RenderWindow* gameWindow_ref)
{
	objectManager = objectManager_ref;
	gameWindow = gameWindow_ref;
}

void LevelManager::CreateLevel(int index)
{
	//objectManager->CreateSquareObject()
	switch (index)
	{
	case 1:
		backgroundImage.loadFromFile("Assets/Textures/bg.jpeg");
		backgroundTexture.loadFromImage(backgroundImage);
		background = sf::RectangleShape(sf::Vector2f(1600, 800));
		background.setTexture(&backgroundTexture);

		objectManager->CreateSquareObject(0, 525, 445, 882, 32, sf::Color::Red);
		objectManager->CreateSquareObject(1, 75, 85, 16, 32, sf::Color::Blue);
		objectManager->CreateSquareObject(2, 155, 105, 46, 32, sf::Color::Green);
		objectManager->CreateSquareObject(3, 335, 35, 16, 32, sf::Color::Black);

		break;
	default:
		
		break;
	}
}

void LevelManager::Update()
{
	gameWindow->draw(background);
}
