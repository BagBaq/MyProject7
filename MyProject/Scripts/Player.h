#ifndef PLAYER_H
#define PLAYER_H
#include "Source.h"

class Player {
private:
	//bool right, left, down, up;
	float offset;
	WholeBody p_pBody;
	b2World* p_world;
	sf::Texture p_pImage;
	float p_xPos;
	float p_yPos;
	float p_xSize;
	float p_ySize;
public:
	Player(b2World* aWorld, sf::Image& image);
	~Player();

	void SetCollider();
	void SetPosition(float x, float y);
	void Input(sf::Event events);
	void Draw();
	void Update();
};

#endif