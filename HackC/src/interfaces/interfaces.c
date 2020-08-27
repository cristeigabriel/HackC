#include "../../include/interfaces/interfaces.h"
#include "../../include/memory/memory.h"

interfaces_t interfaces;

const void interfaces_initialize(void)
{
    interfaces.client = interfaces_scanner("client.dll", "VClient018");
    interfaces.client_mode = **((void***)(interfaces.client[0][10] + 5));
    interfaces.global_vars = **((void***)(interfaces.client[0][11] + 10));
    interfaces.engine_client = interfaces_scanner("engine.dll", "VEngineClient014");
    interfaces.entity_list = interfaces_scanner("client.dll", "VClientEntityList003");
}

const void interfaces_release(void)
{
    interfaces.client = NULL;
    interfaces.client_mode = NULL;
    interfaces.global_vars = NULL;
    interfaces.engine_client = NULL;
    interfaces.entity_list = NULL;
}