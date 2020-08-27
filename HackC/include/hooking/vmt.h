#pragma once

#include <Windows.h>
#include <TlHelp32.h>
#include <Psapi.h>

#include <memory.h>
#include <assert.h>

#define CALL_ORIGINAL(type, this, vmt, index, ...) (((type)((vmt)[index]))(this, 0, __VA_ARGS__));

struct vmt_hook {
    void* base;
    unsigned int* base_vmt;
    unsigned int* replace_vmt;
    ULONG_PTR vmt_length;
};
