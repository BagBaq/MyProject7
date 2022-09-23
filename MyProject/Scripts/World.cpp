#include "World.h"

World::World()
{
	w_Gravity = b2Vec2(0.f, 9.8f);
	w_world = new b2World(w_Gravity);
	// set resources
	w_res[0].w_backgroundTexture.loadFromFile("../Assets/Textures/bg.png");
	w_res[0].w_playerTexture.loadFromFile("../Assets/Textures/player.jpg");
}

World::~World()
{
	w_world = NULL;
	delete w_world;
	// delete res;
}

b2World* World::getb2World()
{
	return w_world;
}

LevelAssets& World::getRes(int index)
{
	return w_res[index];
}
