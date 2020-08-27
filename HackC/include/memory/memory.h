#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include <Windows.h>
#include <PsApi.h>

typedef struct {
    void* test;
} memory_t;

// credits: @danielkrupinski / Anubis, check GitHub description for link
#define call_virtual_method(type, this, index, ...) (((type)(((PUINT*)(this))[0][index]))(this, 0, __VA_ARGS__));

static void* memory_pattern_scanner(const char* module, const char* pattern, const ULONG_PTR offset)
{
    MODULEINFO module_info;
    const HMODULE module_handle = GetModuleHandleA(module);

    if (module_handle && GetModuleInformation(GetCurrentProcess(), module_handle, &module_info, sizeof(module_info)))
    {
        const PCHAR begin = module_info.lpBaseOfDll;
        const PCHAR end = begin + module_info.SizeOfImage;

        for (PCHAR jt = begin; jt != end; ++jt)
        {
            bool matched = true;

            for (PCSTR pattern_it = pattern, it = jt; *pattern_it; pattern_it++, ++it)
            {
                // [this comment will be removed at some point]
                // [most likely when I write a guideline section]
                // quoting quora:

                // Learn that small things matter. For example, write if (0 == value) instead of if (value == 0).
                // This causes the compiler to complain if (no, I mean when) you accidentally forget one =

                // doing this just to avoid comments on it, I'll make it a standard throughout the code, just in case.
                // kind regards
                if ('?' != *pattern_it && *it != *pattern_it) {
                    matched = false;
                    break;
                }
            }

            if (matched)
            {
                printf("found pattern %s at %s + %d\n", module, pattern, offset);
                return jt + offset;
            }
        }
    }
    return NULL;
}

const void memory_initialize(void);
const void memory_release(void);

extern memory_t memory;