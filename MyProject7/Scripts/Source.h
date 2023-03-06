#ifndef SOURCE_H
#define SOURCE_H
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>

#include "ObjectManager.h"
#include "LevelManager.h"
#include "Player.h"
#include "GUIManager.h"

const int gameFramerateLimit = 144; //fps artýnca hýzlanýo
const int METPX = 30;
const std::string gameWindowTitle = "MyProject7";
const bool PlayerGradualAcceleration = false;
const float PlayerSpeed = 7.0f;

 
#endif