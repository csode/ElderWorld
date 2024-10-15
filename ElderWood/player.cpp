#include "player.h"

Player::Player()
{
	player = LoadTexture("C:\\Users\\Tadios\\source\\repos\\ElderWood\\assets\\pictures\\player\\stand.png");
	player_up = LoadTexture("C:\\Users\\Tadios\\source\\repos\\ElderWood\\assets\\pictures\\player\\up.png");
	player_down = LoadTexture("C:\\Users\\Tadios\\source\\repos\\ElderWood\\assets\\pictures\\player\\down.png");
	player_back = LoadTexture("C:\\Users\\Tadios\\source\\repos\\ElderWood\\assets\\pictures\\player\\defence.png");
	player_run = LoadTexture("C:\\Users\\Tadios\\source\\repos\\ElderWood\\assets\\pictures\\player\\forward.png");
	player_backward = LoadTexture("C:\\Users\\Tadios\\source\\repos\\ElderWood\\assets\\pictures\\player\\backward.png");
	player_attack = LoadTexture("C:\\Users\\Tadios\\source\\repos\\ElderWood\\assets\\pictures\\player\\attack.png");
	player_slide = LoadTexture("C:\\Users\\Tadios\\source\\repos\\ElderWood\\assets\\pictures\\player\\slide.png");
	current = player;
	isMoving = false;
	player_position = { (900.0f - player.width) / 2 , (600.0f - player.height) / 2 };
	mana = 100;
	Player::rectangle_position = player_position;

}

void Player::movement()
{
	DrawTextureV(current,player_position , RAYWHITE);
	if (IsKeyPressed(KEY_A)) {
		current = player;
		if (IsKeyDown(KEY_LEFT)) {
			player_position.x -= dash_speed;
			rectangle_position = player_position;
			isMoving = true;
			attack_forward(mana, rectangle_position, is_spell_moving, attack_speed);
			
		}
		else if (IsKeyDown(KEY_UP)) {

			player_position.y -= dash_speed;
			rectangle_position = player_position;
			isMoving = true;
			fire_up(mana, rectangle_position, is_spell_moving, attack_speed);
		}
		else {
			
			isMoving = true;
			
		}

	}
	if (IsKeyDown(KEY_UP)) {
		current = player_up;
		player_position.y -= mvt_running_speed;
		isMoving = true;
		rectangle_position = player_position;
		fire_up(mana, rectangle_position, is_spell_moving, attack_speed);
	}
	else if (IsKeyPressed(KEY_D)) {
		if (IsKeyDown(KEY_RIGHT)) {

			player_position.x += dash_speed;
			rectangle_position = player_position;
			fire_back(mana, rectangle_position, is_spell_moving, attack_speed);
			isMoving = true;
			}
		else if (IsKeyDown(KEY_DOWN)) {
			player_position.y += dash_speed;
			rectangle_position = player_position;
			fire_back(mana, rectangle_position, is_spell_moving, attack_speed);
			isMoving = true;
		}
		else {
			isMoving = true;
		}
	}
	else if (IsKeyDown(KEY_DOWN)) {
		current = player_down;
		player_position.y += mvt_running_speed;
		rectangle_position = player_position;
		fire_down(mana, rectangle_position, is_spell_moving, attack_speed);
		isMoving = true;
	}
	else if (IsKeyDown(KEY_RIGHT)) {
		current = player_run;
		player_position.x += mvt_running_speed;
		rectangle_position = player_position;
		fire_back(mana, rectangle_position, is_spell_moving, attack_speed);
	}
	else if (IsKeyDown(KEY_LEFT)) {
		current = player_backward;
		player_position.x -= mvt_running_speed;
		attack_forward(mana, rectangle_position, is_spell_moving, attack_speed);

	}
	if (!isMoving) {
		current = player;
		attack_forward(mana, rectangle_position, is_spell_moving, attack_speed);

	}
	basic_attack();



}

void Player::basic_attack()
{
	if (IsKeyPressed(KEY_SPACE)) {
		current = player_attack;
		isMoving = true;
	}
	if (IsKeyPressed(KEY_S)) {
		current = player_slide;
		isMoving = true;
	}
	if (IsKeyPressed(KEY_W)) {
		current = player;
		isMoving = true;
	}

}
void Player::attack_forward( int mana, Vector2 rectangle_position, bool is_spell_moving, float attack_speed) {
			if (IsKeyPressed(KEY_F) && !is_spell_moving) {
				if (mana > 5) {
					DrawRectangleV(rectangle_position, { 10, 10 }, BLACK);
					rectangle_position.x += attack_speed;
					mana = mana - 5;
					is_spell_moving = true;

				}
				if (rectangle_position.x > GetScreenWidth()) {
					is_spell_moving = false;
				}
			}
	}



void Player :: fire_down(int mana ,Vector2 rectangle_position, bool is_spell_moving, float attack_speed) {
	if (IsKeyPressed(KEY_F) && !is_spell_moving) {
		if (mana > 5) {
			DrawRectangleV(rectangle_position, { 10, 10 }, BLACK);
			rectangle_position.x -= attack_speed;
			mana = mana - 5;
			is_spell_moving = true;

		}
	if (rectangle_position.x > GetScreenWidth()) {
		is_spell_moving = false;
	}
	}
}

void Player::fire_up(int mana, Vector2 rectangle_position, bool is_spell_moving, float attack_speed) {

	if (IsKeyPressed(KEY_F) && !is_spell_moving) {
		if (mana > 5) {
			DrawRectangleV(rectangle_position, { 10, 10 }, BLACK);
			rectangle_position.y += attack_speed;
			mana = mana - 5;
			is_spell_moving = true;

		}
	if (rectangle_position.y > GetScreenHeight()) {
		is_spell_moving = false;
	}
	}
}

void Player::fire_back(int mana, Vector2 rectangle_position, bool is_spell_moving, float attack_speed)
{
	if (IsKeyPressed(KEY_F) && !is_spell_moving) {
		if (mana > 5) {
			DrawRectangleV(rectangle_position, { 10, 10 }, BLACK);
			rectangle_position.x -= attack_speed;
			mana = mana - 5;
			is_spell_moving = true;

		}
	if (rectangle_position.y > GetScreenHeight()) {
		is_spell_moving = false;
	}
	}
}



