#pragma once

#include <stdbool.h>
#include <inttypes.h>

typedef enum {
	GET_PLAYER_INFO = 8,
	GET_PLAYER_FOR_UID = 9,
	GET_LOCAL_PLAYER = 12,
	GET_MAX_CLIENTS = 20,
	IS_IN_GAME = 26,
	IS_CONNECTED = 27,
	GET_LEVEL_NAME = 53,
	CLIENT_CMD_UNRESTRICTED = 114
} engine_client_indexes;

typedef struct {
	uint64_t version;
	union {
		uint64_t x_uid;
		struct {
			uint32_t x_uid_low;
			uint32_t x_uid_high;
		};
	};
	char name[128];
	int user_id;
	char g_uid[33];
	uint32_t friends_id;
	char friends_name[128];
	bool fake_player;
	bool hltv;
	int custom_files[4];
	unsigned char files_downloaded;
	int entity_index;
} player_info_t;

bool engine_client_get_player_info(int entity_index, const player_info_t* player_info);
int engine_client_get_player_for_uid(int uid);
int engine_client_get_local_player(void);
int engine_client_get_max_clients(void);
bool engine_client_is_in_game(void);
bool engine_client_is_connnected(void);
bool engine_client_is_in_game_and_connected(void);
const char* engine_client_get_level_name(void);
void engine_client_client_cmd_unrestricted(const char* command);