#include "Level.h"

Level::Level(b2World* aWorld, Player* player, sf::Image& image) : L_world(aWorld), L_thePlayer(player)
{
	L_bgTexture.loadFromImage(image);
	L_background = sf::RectangleShape(sf::Vector2f(1000, 800));
	L_background.setTexture(&L_bgTexture);
	CreateWallsFloorCeiling();
	//createPlatforms();
}

Level::~Level()
{
	for (int i = 0; i < 3; i++) {
		L_wallsFloorCeiling[i].w_body->DestroyFixture(L_wallsFloorCeiling[i].w_body->GetFixtureList());
		L_world->DestroyBody(L_wallsFloorCeiling[i].w_body);
	}
}

void Level::Input(sf::Event events)
{
	L_thePlayer->Input(events);
}

void Level::CreateWallsFloorCeiling()
{
	// Floor
	CreateHBorder(L_wallsFloorCeiling[0], (float)450, (float)600, (float)500, (float)25);
	// Left wall
	CreateVBorder(L_wallsFloorCeiling[1], (float)12.5, (float)200, (float)25, (float)400);
	// Right wall
	CreateVBorder(L_wallsFloorCeiling[2], (float)887.5, (float)200, (float)25, (float)400);
}

void Level::CreateHBorder(WholeBody& body, float xpos, float ypos, float xSize, float ySize)
{
	body.w_bodyDef.position.Set(xpos / s_METPX, ypos / s_METPX);
	body.w_bodyDef.type = b2_staticBody;
	body.w_rect = sf::RectangleShape(sf::Vector2f(xSize * 2, ySize));
	body.w_rect.setOrigin(xSize, ySize / 2);
	body.w_rect.setFillColor(sf::Color::Red);
	body.w_shape.SetAsBox(xSize / s_METPX, (ySize / 2) / s_METPX);
	body.w_fixture.shape = &body.w_shape;
	body.w_fixture.density = .7f;
	body.w_fixture.friction = .9f;
	body.w_body = L_world->CreateBody(&body.w_bodyDef);
	body.w_body->CreateFixture(&body.w_shape, 1.0f);
	// set position
	body.w_rect.setPosition(body.w_body->GetPosition().x * s_METPX, body.w_body->GetPosition().y * s_METPX);
}

void Level::CreateVBorder(WholeBody& body, float xpos, float ypos, float xSize, float ySize)
{
	body.w_bodyDef.position.Set(xpos / s_METPX, ypos / s_METPX);
	body.w_bodyDef.type = b2_staticBody;
	body.w_rect = sf::RectangleShape(sf::Vector2f(xSize, ySize * 2));
	body.w_rect.setOrigin(xSize / 2, ySize);
	body.w_rect.setFillColor(sf::Color::Green);
	body.w_shape.SetAsBox((xSize / 2) / s_METPX, ySize / s_METPX);
	body.w_fixture.shape = &body.w_shape;
	body.w_fixture.density = .7f;
	body.w_fixture.friction = .9f;
	body.w_body = L_world->CreateBody(&body.w_bodyDef);
	body.w_body->CreateFixture(&body.w_shape, 1.0f);
	// set position 
	body.w_rect.setPosition(body.w_body->GetPosition().x * s_METPX, body.w_body->GetPosition().y * s_METPX);
}

void Level::Draw()
{
	s_gameWindow.draw(L_background);
	// Draw floor and walls
	for (int i = 0; i < 3; i++) s_gameWindow.draw(L_wallsFloorCeiling[i].w_rect);

	L_thePlayer->Draw();
}

void Level::Update()
{
	L_thePlayer->Update();
}
