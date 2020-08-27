#include "../../../include/interfaces/interfaces.h"
#include "../../../include/memory/memory.h"

bool engine_client_get_player_info(int entity_index, const player_info_t* player_info)
{
    return call_virtual_method(bool(__fastcall*)(void*, void*, int, const player_info_t*), interfaces.engine_client, GET_PLAYER_INFO, entity_index, player_info);
}

int engine_client_get_player_for_uid(int uid)
{
    return call_virtual_method(int(__fastcall*)(void*, void*, int), interfaces.engine_client, GET_PLAYER_FOR_UID, uid);
}

int engine_client_get_local_player(void)
{
    return call_virtual_method(int(__fastcall*)(void*, void*), interfaces.engine_client, GET_LOCAL_PLAYER);
}

int engine_client_get_max_clients(void)
{
    return call_virtual_method(int(__fastcall*)(void*, void*), interfaces.engine_client, GET_MAX_CLIENTS);
}

bool engine_client_is_in_game(void)
{
    return call_virtual_method(bool(__fastcall*)(void*, void*), interfaces.engine_client, IS_IN_GAME);
}

bool engine_client_is_connnected(void)
{
    return call_virtual_method(bool(__fastcall*)(void*, void*), interfaces.engine_client, IS_CONNECTED);
}

bool engine_client_is_in_game_and_connected(void)
{
    return engine_client_is_in_game() && engine_client_is_connnected();
}

const char* engine_client_get_level_name(void)
{
    return call_virtual_method(const char* (__fastcall*)(void*, void*), interfaces.engine_client, GET_LEVEL_NAME);
}
void engine_client_client_cmd_unrestricted(const char* command)
{
    call_virtual_method(void(__fastcall*)(void*, void*, const char*, bool), interfaces.engine_client, CLIENT_CMD_UNRESTRICTED, command, false);
}
