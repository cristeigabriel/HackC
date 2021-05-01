#include "../../include/hooking/hooks.h"
#include "../../include/interfaces/interfaces.h"

#include "../../include/features/movement.h"

hooking_t g_hooking;

static bool __stdcall create_move_hook(float input_sample_time, user_cmd_t* cmd)
{
	CALL_ORIGINAL(bool(__fastcall*)(void*, void*, float, user_cmd_t*), g_interfaces.m_client_mode, g_hooking.m_client_mode.m_original_table, CREATE_MOVE, input_sample_time, cmd);

	if (!cmd || !cmd->command_number || !input_sample_time || !engine_client_is_in_game_and_connected()) {
		return CALL_ORIGINAL(bool(__fastcall*)(void*, void*, float, user_cmd_t*), g_interfaces.m_client_mode, g_hooking.m_client_mode.m_original_table, CREATE_MOVE, input_sample_time, cmd);
	}

	cmd->buttons |= IN_BULLRUSH;

	return true;
}

static void __stdcall frame_stage_notify_hook(hooking_frame_stages_t stage)
{
	CALL_ORIGINAL(void(__fastcall*)(void*, void*, hooking_frame_stages_t), g_interfaces.client, g_hooking.client.original_table, FRAME_STAGE_NOTIFY, stage);
}

void hooking_initialize(void)
{
	hooking_hook_table(g_interfaces.m_client, &g_hooking.m_client);
	hooking_hook_method(&g_hooking.m_client, FRAME_STAGE_NOTIFY, frame_stage_notify_hook);

	hooking_hook_table(g_interfaces.m_client_mode, &g_hooking.m_client_mode);
	hooking_hook_method(&g_hooking.m_client_mode, CREATE_MOVE, create_move_hook);
}

void hooking_release(void)
{
	hooking_unhook_table(&g_hooking.m_client);
	hooking_unhook_table(&g_hooking.m_client_mode);
}

