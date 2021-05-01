#pragma once

#include <Windows.h>
#include <TlHelp32.h>
#include <Psapi.h>

#include <memory.h>
#include <assert.h>

#include <stdint.h>

typedef struct {
	uintptr_t** m_table;
	uintptr_t* m_original_table;
	uintptr_t* m_replacement_table;
	uint32_t m_table_size;
} vmt_hook_t;

//  Most credits directed towards Anubis/@danielkrupinski

void hooking_hook_table(vmt_hook_t* vmt, void* table);
void hooking_unhook_table(vmt_hook_t* vmt);
void hooking_hook_method(vmt_hook_t* vmt, uint32_t index, void* function);
void hooking_unhook_method(vmt_hook_t* vmt, uint32_t index);

#define CALL_ORIGINAL(type, this, vmt, index, ...) (((type)((vmt)[index]))(this, 0, __VA_ARGS__));
