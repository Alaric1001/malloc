#include "malloc/malloc.h"
#include "utils/utils.h"

#include "libft/output/obuff.h"

t_area_and_type	get_lowest_area(t_area** tiny, t_area** small, t_area** large)
{
	t_area_and_type ret;

	ret.area = *tiny;
	if (*small && (*small < ret.area || !ret.area))
	{
		ret.area = *small;
		ret.type = SMALL;
		*small = (*small)->next;
	}
	if (*large && (*large < ret.area || !ret.area))
	{
		ret.area = *large;
		ret.type = LARGE;
		*large = (*large)->next;
	}
	if (ret.area && ret.area == *tiny)
	{
		*tiny = (*tiny)->next;
		ret.type = TINY;
	}
	return (ret);
}

const char* get_type_str(t_block_type type)
{
	static const char *types[] = { "TINY\0", "SMALL\0", "LARGE\0" };

	return (types[type]);
}
