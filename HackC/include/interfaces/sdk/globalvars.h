#pragma once

#include <inttypes.h>
#include <stdbool.h>

typedef struct {
	float real_time;
	int frame_count;
	float absolute_frame_time;
	float absolute_frame_time_std_dev;
	float current_time;
	float frame_time;
	int max_clients;
	int tick_count;
	float interval_per_tick;
	float interpolation_amount;
	int simulated_ticks_per_frame;
	int network_protocol;
	void* save_data;
	bool client;
	bool remote_client;
} globalvars_t;

