#ifndef WORLD_H
#define WORLD_H
#include <box2d/box2d.h>
#include <SFML\Graphics.hpp>

struct WholeBody {
	b2BodyDef w_bodyDef;
	b2PolygonShape w_shape;
	b2FixtureDef w_fixture;
	b2Body* w_body;
	sf::RectangleShape w_rect;
};

struct LevelAssets {
	sf::Image w_backgroundTexture;
	sf::Image w_playerTexture;
};

class World {
private:
	LevelAssets w_res[1]; // only one "level"

	b2World* w_world;
	b2Vec2 w_Gravity;
public:
	World();
	~World();
	b2World* getb2World();
	LevelAssets& getRes(int index); // return res[index]
};
#endif