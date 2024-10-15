#include "win.h"
#include "player.h"

Win::Win()
{
	InitAudioDevice();


	screen_height = 600;
	screen_width = 900;

	
	InitWindow(screen_width, screen_height, "ElderWood");


	intro_sound = LoadSound("C:\\Users\\Tadios\\source\\repos\\ElderWood\\assets\\sound\\intro.wav");
	Player player;


	SetTargetFPS(60);
	
	PlaySound(intro_sound);
	while (!WindowShouldClose()) {

	BeginDrawing();
	ClearBackground(GREEN);
	welcomeScreen();
	player.movement();
	EndDrawing();
	}
	UnloadSound(intro_sound);
	CloseAudioDevice();
	CloseWindow();

}

void Win::welcomeScreen()
{
	DrawText("WELCOME TO ELDERWOOD", 190, 20, 40, WHITE);
}
