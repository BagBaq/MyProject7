#include "GUIManager.h"

GUIManager::GUIManager(sf::RenderWindow* gameWindow_ref) : gameWindow(gameWindow_ref)
{
	MainFont.loadFromFile("Assets/Fonts/bahnschrift.ttf");
	InitializeTexts();
}

GUIManager::~GUIManager()
{

}

void GUIManager::Update(int fps)
{
	fpsCount.setString(std::to_string(fps));
	gameWindow->draw(fpsCount);
}

void GUIManager::InitializeTexts()
{
	fpsCount.setFont(MainFont);
	fpsCount.setCharacterSize(30);
	fpsCount.setFillColor(sf::Color::Red);
	fpsCount.setPosition(sf::Vector2f(100.f, 100.f));
}
