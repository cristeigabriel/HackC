#include "include/memory/memory.h"
#include "include/interfaces/interfaces.h"
#include "include/hooking/hooks.h"

BOOL APIENTRY DllMain(_In_ HMODULE module, _In_ DWORD reason_for_call, _In_opt_ LPVOID reserved)
{
	switch (reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		AllocConsole();
		SetConsoleTitleA("HackC");

		freopen_s((FILE**)(stdin), "CONIN$", "r", stdin);
		freopen_s((FILE**)(stdout), "CONOUT$", "w", stdout);

		memory_initialize();
		interfaces_initialize();
		hooking_initialize();
		break;
	case DLL_PROCESS_DETACH:
		hooking_release();
		memory_release();

		fflush(stdin);
		fflush(stdout);

		fclose(stdin);
		fclose(stdout);

		FreeConsole();
		PostMessageW(GetConsoleWindow(), WM_CLOSE, 0, 0);
		Beep(10, 1000);
		break;
	}
	return TRUE;
}