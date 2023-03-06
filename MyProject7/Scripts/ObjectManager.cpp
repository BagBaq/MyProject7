#include "ObjectManager.h"

ObjectManager::ObjectManager(b2World* box2dWorld_ref, sf::RenderWindow* gameWindow_ref)
{
	box2dWorld = box2dWorld_ref;
	gameWindow = gameWindow_ref;
}

void ObjectManager::CreateSquareObject(int objectIndex, float xpos, float ypos, float xSize, float ySize, sf::Color objectColor) // STATIK DUVAR
{
	// SFML
	SquareObjectList[objectIndex].w_rect = sf::RectangleShape(sf::Vector2f(xSize, ySize * 2));
	SquareObjectList[objectIndex].w_rect.setOrigin(xSize / 2, ySize); // TAM ÜST ORTA
	SquareObjectList[objectIndex].w_rect.setFillColor(objectColor);
	// BOX2D
	SquareObjectList[objectIndex].w_bodyDef.position.Set(xpos / METPX, ypos / METPX);
	SquareObjectList[objectIndex].w_bodyDef.type = b2_staticBody;
	SquareObjectList[objectIndex].w_shape.SetAsBox((xSize / 2) / METPX, ySize / METPX);
	SquareObjectList[objectIndex].w_fixture.shape = &SquareObjectList[objectIndex].w_shape;
	SquareObjectList[objectIndex].w_fixture.density = .7f;
	SquareObjectList[objectIndex].w_fixture.friction = .9f;
	SquareObjectList[objectIndex].w_body = box2dWorld->CreateBody(&SquareObjectList[objectIndex].w_bodyDef);
	SquareObjectList[objectIndex].w_body->CreateFixture(&SquareObjectList[objectIndex].w_shape, 1.0f);
	// Set Position (SFML) 
	SquareObjectList[objectIndex].w_rect.setPosition(SquareObjectList[objectIndex].w_body->GetPosition().x * METPX, SquareObjectList[objectIndex].w_body->GetPosition().y * METPX);
}

void ObjectManager::ClickSpawnObject(float xpos, float ypos, float xsize, float ysize, sf::Color color)
{
	WholeBody object;
	// SFML
	object.w_rect = sf::RectangleShape(sf::Vector2f(xsize, ysize));
	object.w_rect.setOrigin(xsize / 2, ysize / 2); // TAM ORTA
	object.w_rect.setFillColor(sf::Color::Magenta);
	// BOX2D
	object.w_bodyDef.position.Set(xpos / METPX, ypos / METPX);
	object.w_bodyDef.type = b2_dynamicBody;
	object.w_shape.SetAsBox((xsize / 2) / METPX, (ysize / 2) / METPX);
	object.w_fixture.shape = &object.w_shape;
	object.w_fixture.density = .7f;
	object.w_fixture.friction = .9f;
	object.w_body = box2dWorld->CreateBody(&object.w_bodyDef);
	object.w_body->CreateFixture(&object.w_shape, 1.0f);
	// Set Position (SFML) 
	object.w_rect.setPosition(object.w_body->GetPosition().x * METPX, object.w_body->GetPosition().y * METPX);

	ClickSpawnObjectList.push_back(object);
}

void ObjectManager::Update()
{
	for (int i = 0; i < 4; i++) gameWindow->draw(SquareObjectList[i].w_rect);
	for (auto it = std::begin(ClickSpawnObjectList); it != std::end(ClickSpawnObjectList); ++it) 
	{
		it->w_rect.setPosition(it->w_body->GetPosition().x * METPX, it->w_body->GetPosition().y * METPX);
		gameWindow->draw(it->w_rect);
	}
}

void ObjectManager::DeleteAllObjects()
{
	for (int i = 0; i < 4; i++) {
		SquareObjectList[i].w_body->DestroyFixture(SquareObjectList[i].w_body->GetFixtureList());
		box2dWorld->DestroyBody(SquareObjectList[i].w_body);
	}
}