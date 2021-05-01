#include "../../../include/interfaces/interfaces.h"
#include "../../../include/memory/memory.h"

client_class_t* client_get_all_classes()
{
	return CALL_VIRTUAL_METHOD(client_class_t * (__fastcall*)(void*, void*), g_interfaces.m_client, GET_ALL_CLASSES);
}

bool client_dispatch_user_message(int message_type, unsigned int arg_1, unsigned int arg_2)
{
	return CALL_VIRTUAL_METHOD(bool(__fastcall*)(void*, void*, int, unsigned int, unsigned int, const void*), g_interfaces.m_client, DISPATCH_USER_MESSAGE, message_type, arg_1, arg_2, NULL);
}