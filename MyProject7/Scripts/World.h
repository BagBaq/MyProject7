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

class World {
private:
public:
	World();
	~World();
};
#endif