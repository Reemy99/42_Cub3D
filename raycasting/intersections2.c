

#include "../include/include.h"

void	horizontal_inter_helper(t_all *data, double ang, \
		int *index_x, int *index_y)
{
	if (is_up(ang))
	{
		*index_x = floor(data->norm.first_x / CUB);
		*index_y = floor((data->norm.first_y - 1) / CUB);
	}
	else
	{
		*index_x = floor(data->norm.first_x / CUB);
		*index_y = floor((data->norm.first_y) / CUB);
	}
}
