#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H
#include "Source.h"

class ObjectManager;

class LevelManager {
private:
	ObjectManager* objectManager;
	sf::RenderWindow* gameWindow;

	sf::RectangleShape background;
	sf::Image backgroundImage;
	sf::Texture backgroundTexture;
public:
	LevelManager(ObjectManager* objectManager_ref, sf::RenderWindow* gameWindow_ref);
	void CreateLevel(int index);
	void Update();
};
#endif