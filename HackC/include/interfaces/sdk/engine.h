#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef enum {
	GET_PLAYER_INFO = 8,
	GET_PLAYER_FOR_UID = 9,
	GET_LOCAL_PLAYER = 12,
	GET_MAX_CLIENTS = 20,
	IS_IN_GAME = 26,
	IS_CONNECTED = 27,
	GET_LEVEL_NAME = 53,
	CLIENT_CMD_UNRESTRICTED = 114
} engine_client_indexes_t;

typedef struct {
	uint64_t m_version;
	union {
		uint64_t m_steamid64;
		struct {
			uint32_t m_x_uid_low;
			uint32_t m_x_uid_high;
		};
	};
	char m_name[32];
	int m_user_id;
	char m_guid[32 + 1];
	uint32_t m_friends_id;
	char m_friends_name[32];
	bool m_fake_player;
	bool m_is_hltv;
	int m_custom_files[4];
	char m_files_downloaded;
} player_info_t;

typedef struct {
	char pad1[64];
} engine_client_t;

bool engine_client_get_player_info(int entity_index, const player_info_t* player_info);
int engine_client_get_player_for_uid(int uid);
int engine_client_get_local_player(void);
int engine_client_get_max_clients(void);
bool engine_client_is_in_game(void);
bool engine_client_is_connnected(void);
bool engine_client_is_in_game_and_connected(void);
const char* engine_client_get_level_name(void);
void engine_client_client_cmd_unrestricted(const char* command);