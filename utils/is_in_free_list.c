#include "utils/utils.h"

int is_in_free_list(const t_block* b, const t_block* free_list)
{
	while (free_list)
	{
		if(free_list == b)
			return (1);
		free_list = free_list->next_free;
	}
	return (0);
}
