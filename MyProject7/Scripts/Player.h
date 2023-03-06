#ifndef PLAYER_H
#define PLAYER_H
#include "Source.h"
#include "World.h"

class Player {
private:
	WholeBody p_pBody;
	b2World* p_world;
	sf::RenderWindow* p_gameWindow_ref;
	sf::Texture playerTexture;
	sf::Image playerImage;

	float p_xPos, p_yPos, p_xSize, p_ySize;

	enum PlayerMoveState
	{
		Left,
		Right,
		Null,
	};

	PlayerMoveState playerMoveState;
public:
	Player(b2World* aWorld, sf::RenderWindow* s_gameWindow_ref);
	~Player();

	void SetCollider();
	void SetPosition(float x, float y);
	void Movement(sf::Event e);
	void Update(sf::Event e);
	sf::Vector2f ReturnPosition();
};

#endif