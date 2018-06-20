#include "utils/utils.h"

#ifndef round_up
# define round_up(num, align) (((num) + ((align) - 1)) & ~((align) - 1))
#endif

#include <stdio.h>
size_t round_size(t_block_type type, size_t size)
{
	if (type == TINY)	
		return round_up(size, 16ul);
	if (type == SMALL)
		return round_up(size, 512ul);
	return size;
}
