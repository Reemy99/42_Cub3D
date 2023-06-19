
#include "../include/include.h"

int	check_map(t_all *data)
{
	init_map(data);
	add_space(data);
	if (check_characters(data))
	{
		free_maps(data);
		printf("invalid map characters\n");
		return (1);
	}
	if (check_valid_map(data))
	{
		free_maps(data);
		printf("invalid map \n");
		return (1);
	}
	init_angle(data);
	return (0);
}
