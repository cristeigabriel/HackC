#include "../../../include/interfaces/interfaces.h"
#include "../../../include/memory/memory.h"

struct client_class* client_get_all_classes()
{
	return call_virtual_method(struct client_class* (__fastcall*)(void*, void*), interfaces.client, GET_ALL_CLASSES);
}

bool client_dispatch_user_message(int message_type, unsigned int arg_1, unsigned int arg_2)
{
	return call_virtual_method(bool(__fastcall*)(void*, void*, int, unsigned int, unsigned int, const void*), interfaces.client, DISPATCH_USER_MESSAGE, message_type, arg_1, arg_2, NULL);
}