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
	uintptr_t** client;
	void** client_mode;
	globalvars_t* global_vars;
	uintptr_t** engine_client;
	uintptr_t** entity_list;
} interfaces_t;

// "warning C4133: '='; incompatible types - from 'uintptr_t **' to 'uintptr_t **'", nice
#pragma warning(disable:4133)

static uintptr_t** interfaces_scanner(const char* module, const char* name)
{
	// int __cdecl CreateInterface(int a1, int a2)
	typedef uintptr_t** (*CreateInterface_t)(const char*, int*); // prototype

	// get handle to .dll file
	const HMODULE module_handle = GetModuleHandleA(module);

	if (module_handle)
	{
		// initialize scope with prototype
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

const void interfaces_initialize(void);
const void interfaces_release(void);

extern interfaces_t interfaces;