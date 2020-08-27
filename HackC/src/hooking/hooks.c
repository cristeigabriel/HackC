#include "../../include/hooking/hooks.h"
#include "../../include/interfaces/interfaces.h"
#include "../../include/globals/globals.h"

#include "../../include/features/movement.h"

hooking_t hooking;

#pragma region vmt hook
// i've took the liberty to take a part of
// @danielkrupinski's VMT hooking class
// in accordance to his project's license
// and have changed the table length
// calculation method to the one that i use
// in my projects alongside also
// tinkering with naming, arglist
// and some memory allocation

// thank you for your work @danielkrupinski
// i've learned many new things from your
// projects

static ULONG_PTR hooking_table_calculate_length(const uintptr_t* table)
{
    uintptr_t length;

    for (length = 0; table[length]; length++)
        if (IS_INTRESOURCE(table[length]))
            break;

    return length;
}

static void hooking_hook_table(void* base, struct vmt_hook* vmt)
{
    vmt->base = base;
    vmt->base_vmt = *((unsigned int**)base);
    vmt->vmt_length = hooking_table_calculate_length(vmt->base_vmt) + 1;

    // disclaimer: alloca cannot be used since there'll occur
    // a stack overflow exception, and _malloca only works in C++
    // since it is in <alt_alloca.h> which is not compatible with C.
    void* new_vmt = malloc(vmt->vmt_length * sizeof(uintptr_t));
    if (new_vmt) {
        vmt->replace_vmt = new_vmt;
        memcpy(vmt->replace_vmt, vmt->base_vmt - 1, vmt->vmt_length * sizeof(uintptr_t));
        *((unsigned int**)base) = vmt->replace_vmt + 1;
    }
}

static void hooking_unhook_table(struct vmt_hook* vmt)
{
    *((unsigned int**)vmt->base) = vmt->base_vmt;
    free(vmt->replace_vmt);
}

static void hooking_hook_method(struct vmt_hook* vmt, const ULONG_PTR index, void* function)
{
    if (index < vmt->vmt_length)
        vmt->replace_vmt[index + 1] = (unsigned int)function;
}
#pragma endregion

static bool __stdcall create_move(float input_sample_time, usercmd_t* cmd)
{
    CALL_ORIGINAL(bool(__fastcall*)(void*, void*, float, usercmd_t*), interfaces.client_mode, hooking.client_mode.base_vmt, CREATE_MOVE, input_sample_time, cmd);

    if (!cmd || !cmd->command_number || !input_sample_time || !engine_client_is_in_game_and_connected())
        return CALL_ORIGINAL(bool(__fastcall*)(void*, void*, float, usercmd_t*), interfaces.client_mode, hooking.client_mode.base_vmt, CREATE_MOVE, input_sample_time, cmd);

    // just in case
    globals.cmd = cmd;
    globals.local = entity_list_get_entity(engine_client_get_local_player());

    // wait until I add entity flags
    // movement_autostrafe(cmd);

    cmd->buttons |= IN_BULLRUSH;

    return true;
}

static void __stdcall frame_stage_notify(hooking_frame_stages stage)
{
    CALL_ORIGINAL(void(__fastcall*)(void*, void*, hooking_frame_stages), interfaces.client, hooking.client.base_vmt, FRAME_STAGE_NOTIFY, stage);
}

const void hooking_initialize(void)
{
    hooking_hook_table(interfaces.client, &hooking.client);
    hooking_hook_method(&hooking.client, FRAME_STAGE_NOTIFY, frame_stage_notify);

    hooking_hook_table(interfaces.client_mode, &hooking.client_mode);
    hooking_hook_method(&hooking.client_mode, CREATE_MOVE, create_move);
}

const void hooking_release(void)
{
    hooking_unhook_table(&hooking.client);
    hooking_unhook_table(&hooking.client_mode);
}

