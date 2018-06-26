#include "malloc/malloc.h"
#include "utils/utils.h"

#include "libft/output/obuff.h"

#include <stdio.h>
t_area_and_type	get_lowest_area(t_area** tiny, t_area** small, t_area** large)
{
	t_area_and_type ret;
	t_area			**area;

	area = tiny;
	ret.type = TINY;
	//printf("s=%p, l=%p, t=%p\n", *small, *large, *tiny);
	if (*small && (*small < *area || !*area))
	{
		area = small;
		ret.type = SMALL;
	}
	if (*large && (*large < *area || !*area))
	{
		area = large;
		ret.type = LARGE;
	}
	ret.area = *area;
	if (*area)
		*area = (*area)->next;
	return (ret);
}

const char* get_type_str(t_block_type type)
{
	static const char *types[] = { "TINY\0", "SMALL\0", "LARGE\0" };

	return (types[type]);
}
