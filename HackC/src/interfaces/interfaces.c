#include "../../include/interfaces/interfaces.h"
#include "../../include/memory/memory.h"

interfaces_t g_interfaces;

void interfaces_initialize(void)
{
	g_interfaces.m_client = interfaces_grab("client.dll", "VClient018");
	g_interfaces.m_client_mode = **((void***)(g_interfaces.m_client[0][10] + 5));
	g_interfaces.m_global_vars = **((void***)(g_interfaces.m_client[0][11] + 10));
	g_interfaces.m_engine_client = interfaces_grab("engine.dll", "VEngineClient014");
	g_interfaces.m_entity_list = interfaces_grab("client.dll", "VClientEntityList003");
}