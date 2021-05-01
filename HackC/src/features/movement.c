#include "../../include/features/movement.h"

void movement_autostrafe(user_cmd_t* cmd)
{
	cmd->side_move = cmd->mouse_dx > 0 ? 450.F : -450.F;
}