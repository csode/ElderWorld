#pragma once
#include "raylib.h"
class Player{
public :
	Player();
	void movement();
	void basic_attack();
	void attack_forward(int mana, Vector2 rectangle_position, bool is_spell_moving, float attack_speed);
	void fire_down(int mana, Vector2 rectangle_position, bool is_spell_moving, float attack_speed);
	void fire_up(int mana, Vector2 rectangle_position, bool is_spell_moving, float attack_speed);
	void fire_back(int mana, Vector2 rectangle_position, bool is_spell_moving, float attack_speed);
private :
	Texture2D player, player_up, player_down, player_run, player_back, player_backward,player_attack, player_slide;
	Texture2D current;
	Vector2 player_position;
	float mvt_running_speed = 2.0f;
	float dash_speed = 20.0f;
	bool isMoving;
	int mana;
	bool forward = true;
	Vector2 rectangle_position;
	float attack_speed = 5.0f;
	bool is_spell_moving = false;
	};

