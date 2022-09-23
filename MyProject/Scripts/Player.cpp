#include "Player.h"

Player::Player(b2World* aWorld, sf::Image& image) : p_world(aWorld)
{
	p_pImage.loadFromImage(image);
	p_xPos = 100;
	p_yPos = 100;
	p_xSize = 20;
	p_ySize = 40;
	offset = 10 * 0.3f; //?
	SetCollider();
}

Player::~Player()
{
	p_pBody.w_body->DestroyFixture(p_pBody.w_body->GetFixtureList());
	p_world->DestroyBody(p_pBody.w_body);
}

void Player::SetCollider()
{
	// SFML
	p_pBody.w_rect = sf::RectangleShape(sf::Vector2f(p_xSize * 2, p_ySize));//100-50? is size?
	p_pBody.w_rect.setOrigin(p_xSize, p_ySize / 2);
	p_pBody.w_rect.setTexture(&p_pImage);
	// Box2D
	p_pBody.w_bodyDef.position.Set(p_xPos / s_METPX, p_yPos / s_METPX);
	p_pBody.w_bodyDef.type = b2_dynamicBody;
	p_pBody.w_shape.SetAsBox(p_xSize / s_METPX, (p_ySize / 2) / s_METPX);
	p_pBody.w_fixture.shape = &p_pBody.w_shape;
	p_pBody.w_fixture.density = 1.f;
	p_pBody.w_fixture.friction = .9f;
	p_pBody.w_body = p_world->CreateBody(&p_pBody.w_bodyDef);
	p_pBody.w_body->CreateFixture(&p_pBody.w_shape, 1.0f);
}

void Player::SetPosition(float x, float y)
{
	p_xPos = x;
	p_yPos = y;
	// Box2D
	p_pBody.w_body->DestroyFixture(p_pBody.w_body->GetFixtureList());
	p_world->DestroyBody(p_pBody.w_body);
	p_pBody.w_bodyDef.position.Set(p_xPos / s_METPX, p_yPos / s_METPX - 1 * 5 / s_METPX);

	//playerBody.DEF.angularVelocity = 0;
	//playerBody.DEF.linearVelocity.Set(0, 60);

	p_pBody.w_body = p_world->CreateBody(&p_pBody.w_bodyDef);
	p_pBody.w_body->CreateFixture(&p_pBody.w_fixture);

	// SFML
	p_pBody.w_rect.setPosition(p_pBody.w_body->GetPosition().x * s_METPX, p_pBody.w_body->GetPosition().y * s_METPX);
}

void Player::Input(sf::Event events)
{
}

void Player::Draw()
{
	s_gameWindow.draw(p_pBody.w_rect);
}

void Player::Update()
{
	p_xPos = p_pBody.w_body->GetPosition().x;
	p_yPos = p_pBody.w_body->GetPosition().y;

	/*if (right == true && left == false) {
		//xpos += 5;
		//SetPosition(xpos, ypos);
		//playerBody.BOD->SetAngularVelocity(0);
		playerBody.BOD->SetLinearVelocity(b2Vec2(1, 0));
	}
	else if (right == false && left == true) {
		//xpos -= 5;
		//SetPosition(xpos, ypos);
		//playerBody.BOD->SetAngularVelocity(0);
		playerBody.BOD->SetLinearVelocity(b2Vec2(-1, 0));
	} /*(else if (up == true && down == false) {
		ypos -= offset;
		SetPosition(xpos, ypos);
	} else if (up == false && down == true) {
		ypos += offset;
		SetPosition(xpos, ypos);
	} else {
		playerBody.RECT.SetPosition(xPos * RATIO, yPos * RATIO);
	}*/

	// SFML
	p_pBody.w_rect.setPosition(p_xPos * s_METPX, p_yPos * s_METPX);
}
