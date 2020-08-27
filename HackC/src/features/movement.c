#include "../../include/features/movement.h"

const void movement_autostrafe(usercmd_t* cmd)
{
	cmd->side_move = cmd->mouse_dx > 0 ? 450.f : -450.f;
}