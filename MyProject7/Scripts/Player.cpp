#include "Player.h"

Player::Player(b2World* aWorld, sf::RenderWindow* s_gameWindow_ref) : p_world(aWorld), p_gameWindow_ref(s_gameWindow_ref)
{
	playerImage.loadFromFile("Assets/Textures/player.png");
	playerTexture.loadFromImage(playerImage);

	p_xPos = 100;
	p_yPos = 100;
	p_xSize = 48;
	p_ySize = 48;

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
	p_pBody.w_rect = sf::RectangleShape(sf::Vector2f(p_xSize, p_ySize)); //100-50? is size?
	p_pBody.w_rect.setOrigin((p_xSize / 2), p_ySize / 2);
	p_pBody.w_rect.setTexture(&playerTexture);

	p_pBody.w_rect.setOutlineThickness(1);
	p_pBody.w_rect.setOutlineColor(sf::Color::Red);
	// Box2D
	p_pBody.w_bodyDef.position.Set(p_xPos / METPX, p_yPos / METPX);
	p_pBody.w_bodyDef.type = b2_dynamicBody;
	p_pBody.w_shape.SetAsBox((p_xSize / 2) / METPX, (p_ySize / 2) / METPX);
	p_pBody.w_fixture.shape = &p_pBody.w_shape;
	p_pBody.w_fixture.density = 1.f;
	p_pBody.w_fixture.friction = .9f;
	p_pBody.w_body = p_world->CreateBody(&p_pBody.w_bodyDef);
	p_pBody.w_body->CreateFixture(&p_pBody.w_shape, 1.0f);
}

void Player::SetPosition(float x, float y) // GEREKSÝZ?
{
	p_xPos = x;
	p_yPos = y;
	// Box2D
	p_pBody.w_body->DestroyFixture(p_pBody.w_body->GetFixtureList());
	p_world->DestroyBody(p_pBody.w_body);
	p_pBody.w_bodyDef.position.Set(p_xPos / METPX, p_yPos / METPX - 1 * 5 / METPX);

	//playerBody.DEF.angularVelocity = 0;
	//playerBody.DEF.linearVelocity.Set(0, 60);

	p_pBody.w_body = p_world->CreateBody(&p_pBody.w_bodyDef);
	p_pBody.w_body->CreateFixture(&p_pBody.w_fixture);

	// SFML
	p_pBody.w_rect.setPosition(p_pBody.w_body->GetPosition().x * METPX, p_pBody.w_body->GetPosition().y * METPX);
}

void Player::Movement(sf::Event e)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		playerMoveState = Left;
		p_pBody.w_rect.setScale(-1.f, 1.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		playerMoveState = Right;
		p_pBody.w_rect.setScale(1.f, 1.f);
	}
	else
	{
		playerMoveState = Null;
	}

	b2Vec2 vel = p_pBody.w_body->GetLinearVelocity();
	float desiredVel = 0;
	if (PlayerGradualAcceleration)
	{
		switch (playerMoveState)
		{
		case Left:  desiredVel = b2Max(vel.x - 0.1f, -PlayerSpeed); break;
		case Right: desiredVel = b2Min(vel.x + 0.1f, PlayerSpeed); break;
		case Null:  desiredVel = 0; break;
		}
	}
	else
	{
		switch (playerMoveState)
		{
        case Left:  desiredVel = -PlayerSpeed; break;
		case Right: desiredVel = PlayerSpeed; break;
        case Null:  desiredVel = 0; break;
		}
	}
	float velChange = desiredVel - vel.x;
	float impulse = p_pBody.w_body->GetMass() * velChange; // disregard time factor
	p_pBody.w_body->ApplyLinearImpulse(b2Vec2(impulse, 0), p_pBody.w_body->GetWorldCenter(), true);
}

void Player::Update(sf::Event e)
{
	Movement(e);
	p_xPos = p_pBody.w_body->GetPosition().x;
	p_yPos = p_pBody.w_body->GetPosition().y;

	// SFML
	p_pBody.w_rect.setPosition(p_xPos * METPX, p_yPos * METPX);

	p_gameWindow_ref->draw(p_pBody.w_rect);
}

sf::Vector2f Player::ReturnPosition()
{
	return sf::Vector2f(p_xPos * METPX, p_yPos * METPX);
}
