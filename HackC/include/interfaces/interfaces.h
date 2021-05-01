#pragma once

#include "sdk/client.h"
#include "sdk/globalvars.h"
#include "sdk/engine.h"
#include "sdk/entitylist.h"

#include "sdk/usercmd.h"

#include <Windows.h>
#include <stdio.h>

typedef struct
{
	uintptr_t** m_client;
	void** m_client_mode;
	global_vars_t* m_global_vars;
	uintptr_t** m_engine_client;
	uintptr_t** m_entity_list;
} interfaces_t;

//	immediate todo:
//	completely rewrite this
static uintptr_t** interfaces_grab(const char* module, const char* name)
{
	typedef uintptr_t** (*CreateInterface_t)(const char*, int*);

	const HMODULE module_handle = GetModuleHandleA(module);

	if (module_handle)
	{
		const CreateInterface_t create_interface = (CreateInterface_t)GetProcAddress(module_handle, "CreateInterface");
		uintptr_t** found_interface = create_interface(name, 0);
		if (found_interface)
		{
			printf("found interface %s at %s\n", module, name);
			return found_interface;
		}
	}

	return NULL;
}

void interfaces_initialize(void);

extern interfaces_t g_interfaces;