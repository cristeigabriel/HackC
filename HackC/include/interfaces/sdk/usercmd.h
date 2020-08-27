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
} usercmd_buttons;

// MULTIPLAYER_NUMBER = 150
// UserCmd in CInput = 0x100
// sizeof(UserCmd) in game = 244

// https://github.com/perilouswithadollarsign/cstrike15_src/blob/29e4c1fda9698d5cebcdaf1a0de4b829fa149bf8/game/shared/usercmd.h
typedef struct {
    int _pad;
    int command_number;
    int tick_count;
    struct vector view_angles;
    struct vector aim_direction;
    float forward_move;
    float side_move;
    float up_move;
    int buttons;
    char impulse;
    int weapon_select;
    int weapon_subtype;
    int random_seed;
    short mouse_dx;
    short mouse_dy;
    bool has_been_predicted;
} usercmd_t;
