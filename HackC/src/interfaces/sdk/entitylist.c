#include "../../../include/interfaces/interfaces.h"
#include "../../../include/memory/memory.h"

void* entity_list_get_entity(int index)
{
	return call_virtual_method(void* (__fastcall*)(void*, void*, int), interfaces.entity_list, GET_ENTITY, index);
}

void* entity_list_get_entity_from_handle(int handle)
{
	return call_virtual_method(void* (__fastcall*)(void*, void*, int), interfaces.entity_list, GET_ENTITY_FROM_HANDLE, handle);
}

int entity_list_get_highest_entity_index(void)
{
	return call_virtual_method(int(__fastcall*)(void*, void*), interfaces.entity_list, GET_HIGHEST_ENTITY_INDEX);
}