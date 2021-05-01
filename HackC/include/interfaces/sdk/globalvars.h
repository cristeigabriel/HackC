#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct {
	float m_real_time;
	int m_frame_count;
	float m_absolute_frame_time;
	float m_absolute_frame_time_std_dev;
	float m_current_time;
	float m_frame_time;
	int m_max_clients;
	int m_tick_count;
	float m_interval_per_tick;
	float m_interpolation_amount;
	int m_simulated_ticks_per_frame;
	int m_network_protocol;
	void* m_save_data;
	bool m_client;
	bool m_remote_client;
} global_vars_t;

