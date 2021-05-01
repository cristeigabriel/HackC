#pragma once

#include <stdbool.h>
#include <Windows.h>

#include "../../math/vector.h"

typedef enum {
	IN_ATTACK = 1 << 0,
	IN_JUMP = 1 << 1,
	IN_DUCK = 1 << 2,
	IN_FORWARD = 1 << 3,
	IN_BACK = 1 << 4,
	IN_USE = 1 << 5,
	IN_MOVELEFT = 1 << 9,
	IN_MOVERIGHT = 1 << 10,
	IN_ATTACK2 = 1 << 11,
	IN_SCORE = 1 << 16,
	IN_BULLRUSH = 1 << 22
} usercmd_buttons_t;

#define MULTIPLAYER_NUMBER 150
typedef struct {
	char pad1[4];
	int m_command_number;
	int m_tick_count;
	struct vector_t m_view_angles;
	struct vector_t m_aim_direction;
	float m_forward_move;
	float m_side_move;
	float m_up_move;
	int m_buttons;
	char m_impulse;
	int m_weapon_select;
	int m_weapon_subtype;
	int m_random_seed;
	short m_mouse_dx;
	short m_mouse_dy;
	bool m_has_been_predicted;
} user_cmd_t;
