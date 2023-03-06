#ifndef GUIMANAGER_H
#define GUIMANAGER_H
#include "Source.h"

class GUIManager {
private:
	sf::RenderWindow* gameWindow;
	sf::Font MainFont;

	sf::Text fpsCount;
public:
	GUIManager(sf::RenderWindow* gameWindow_ref);
	~GUIManager();
	void Update(int fps);
	void InitializeTexts();
};

#endif