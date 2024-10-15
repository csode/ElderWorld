#pragma once
#include "raylib.h"
class Win
{
public:
	Win();
	void welcomeScreen();
private:
	int screen_width, screen_height;
	Sound intro_sound;
};

