#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <Windows.h>
#include <PsApi.h>

void memory_initialize(void);
void memory_release(void);

#define CALL_VIRTUAL_METHOD(type, this, index, ...) (((type)(((PUINT*)(this))[0][index]))(this, 0, __VA_ARGS__));
