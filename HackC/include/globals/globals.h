#pragma once

#include "../interfaces/sdk/usercmd.h"

typedef struct {
	usercmd_t* cmd;
	void* local;
} globals_t;

// there might be better ways to do this,
// I just want to make sure that I don't
// make multiple objects of this by accident.
globals_t globals;
