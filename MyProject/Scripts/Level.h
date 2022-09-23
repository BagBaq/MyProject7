#ifndef LEVEL_H
#define LEVEL_H
#include "World.h"
#include "Player.h"
#include "Source.h"

class Player;

class Level {
private:
	WholeBody L_wallsFloorCeiling[4]; // place holder for walls floor and ceiling
	WholeBody L_platforms[7]; // place holder for platforms
	b2World* L_world;
	Player* L_thePlayer;
	sf::Texture L_bgTexture;
	sf::RectangleShape L_background;
public:
	Level(b2World* aWorld, Player* player, sf::Image& image);
	~Level();
	void Input(sf::Event events);
	void CreateWallsFloorCeiling();
	void CreateHBorder(WholeBody& body, float xpos, float ypos, float xSize, float ySize);
	void CreateVBorder(WholeBody& body, float xpos, float ypos, float xSize, float ySize);
	void Draw();
	void Update();
};
#endif