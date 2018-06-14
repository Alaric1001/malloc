#include "utils/utils.h"

#include <unistd.h>

size_t	get_area_size(t_block_type type)
{
	if (type == TINY)
		return (getpagesize() * TINY_AREA_SIZE);
	if (type == SMALL)
		return (getpagesize() * SMALL_AREA_SIZE);
	return (0);
}
