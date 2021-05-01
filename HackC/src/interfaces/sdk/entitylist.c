#include "../../../include/interfaces/interfaces.h"
#include "../../../include/memory/memory.h"

void* entity_list_get_entity(int index)
{
	return CALL_VIRTUAL_METHOD(void* (__fastcall*)(void*, void*, int), g_interfaces.m_entity_list, GET_ENTITY, index);
}

void* entity_list_get_entity_from_handle(int handle)
{
	return CALL_VIRTUAL_METHOD(void* (__fastcall*)(void*, void*, int), g_interfaces.m_entity_list, GET_ENTITY_FROM_HANDLE, handle);
}

int entity_list_get_highest_entity_index(void)
{
	return CALL_VIRTUAL_METHOD(int(__fastcall*)(void*, void*), g_interfaces.m_entity_list, GET_HIGHEST_ENTITY_INDEX);
}