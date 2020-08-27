#pragma once

typedef enum {
	GET_ENTITY = 3,
	GET_ENTITY_FROM_HANDLE = 4,
	GET_HIGHEST_ENTITY_INDEX = 6
} entity_list_indexes;

void* entity_list_get_entity(int index);
void* entity_list_get_entity_from_handle(int handle);
int entity_list_get_highest_entity_index(void);