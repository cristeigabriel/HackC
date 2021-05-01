#pragma once

#include "vmt.h"

typedef struct {
	vmt_hook_t m_client;
	vmt_hook_t m_client_mode;
} hooking_t;

typedef enum {
	CREATE_MOVE = 24,
	FRAME_STAGE_NOTIFY = 37
} hooking_indexes_t;

// https://github.com/perilouswithadollarsign/cstrike15_src/blob/29e4c1fda9698d5cebcdaf1a0de4b829fa149bf8/public/cdll_int.h#L218
typedef enum {
	FRAME_UNDEFINED = -1, // (haven't run any frames yet)
	START,

	// a network packet is being recieved
	NET_UPDATE_START,
	// data has been received and we're going to start calling PostDataUpdate
	NET_UPDATE_POSTDATAUPDATE_START,
	// data has been received and we've called PostDataUpdate on all data
	// recipients
	NET_UPDATE_POSTDATAUPDATE_END,
	// we've received all packets, we can now do interpolation, prediction,
	// etc..
	NET_UPDATE_END,

	// we're about to start rendering the scene
	RENDER_START,
	// we've finished rendering the scene.
	RENDER_END
} hooking_frame_stages_t;

void hooking_initialize(void);
void hooking_release(void);

extern hooking_t g_hooking;