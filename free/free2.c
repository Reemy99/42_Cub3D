

#include "../include/include.h"

void	free_all(t_all *data)
{
	int	i;

	i = 0;
	while (data->parss.all[i])
		free(data->parss.all[i++]);
	free(data->parss.all);
}
