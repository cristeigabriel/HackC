#pragma once

#include <Windows.h>

typedef struct {
	HWND console_handle;
} console_context_t;

const void console_initialize(void);
const void console_release(void);

extern console_context_t console_context;