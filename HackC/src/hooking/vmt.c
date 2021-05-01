#include "../../include/hooking/vmt.h"

//  Most credits directed towards Anubis/@danielkrupinski
void hooking_hook_table(vmt_hook_t* vmt, void* table)
{
	vmt->m_table = table;
	vmt->m_original_table = *((uintptr_t**)table);
	while (vmt->m_original_table[vmt->m_table_size] != NULL) {
		++vmt->m_table_size;
	}

	void* new_table = malloc((vmt->m_table_size + 1) * sizeof(uintptr_t));
	if (new_table) {
		vmt->m_replacement_table = new_table;

		memset(&vmt->m_replacement_table[0], 0, vmt->m_table_size * (sizeof(uintptr_t) * 2));
		memcpy(&vmt->m_replacement_table[1], vmt->m_original_table, vmt->m_table_size * sizeof(uintptr_t));
		memcpy(vmt->m_replacement_table, &vmt->m_original_table[-1], sizeof(uintptr_t));

		*vmt->m_table = &vmt->m_replacement_table[1];
	}
}

void hooking_unhook_table(vmt_hook_t* vmt)
{
	*vmt->m_table = vmt->m_original_table;
	free(vmt->m_replacement_table);
}

void hooking_hook_method(vmt_hook_t* vmt, uint32_t index, void* function)
{
	if (index < vmt->m_table_size) {
		vmt->m_replacement_table[index + 1] = (uintptr_t)function;
	}
}

void hooking_unhook_method(vmt_hook_t* vmt, uint32_t index)
{
	if (index < vmt->m_table_size) {
		vmt->m_replacement_table[index + 1] = vmt->m_original_table[index];
	}
}
