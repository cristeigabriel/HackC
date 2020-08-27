#include "../../include/console/console.h"
#include <stdio.h>

console_context_t console_context;

const void console_initialize(void)
{
	console_context.console_handle = GetConsoleWindow();

	AllocConsole();
	SetConsoleTitleA("HackC");

	freopen_s((FILE**)(stdin), "CONIN$", "r", stdin);
	freopen_s((FILE**)(stdout), "CONOUT$", "w", stdout);

	printf("initialized console\n");
}

const void console_release(void)
{
	// since we use C [and printf], we need
	// to flush buffers before closing the
	// console, and no, I will not do a
	// printf wrapper that solely flushes
	// buffer after every printf because
	// that is utterly [redacted], and you
	// should feel ashamed if you're looking
	// towards doing that
	// fuck you
	fflush(stdin);
	fflush(stdout);

	fclose(stdin);
	fclose(stdout);

	FreeConsole();
	PostMessageW(console_context.console_handle, WM_CLOSE, 0, 0);
	Beep(10, 1000);
}