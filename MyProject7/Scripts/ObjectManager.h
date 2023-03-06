#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H
#include "Source.h"
#include "World.h"

class ObjectManager {
private:
	WholeBody SquareObjectList[4]; // place holder for square objects // burdaki sayý configden çekilebilir
	std::vector<WholeBody> ClickSpawnObjectList;

	b2World* box2dWorld;
	sf::RenderWindow* gameWindow;
public:
	ObjectManager(b2World* box2dWorld_ref, sf::RenderWindow* gameWindow_ref);
	void CreateSquareObject(int ObjectIndex, float xpos, float ypos, float xSize, float ySize, sf::Color objectColor);
	void ClickSpawnObject(float xpos, float ypos, float xsize, float ysize, sf::Color color);
	void Update();
	void DeleteAllObjects();
};
#endif