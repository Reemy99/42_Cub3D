

#include "../include/include.h"

int	get_floor(t_all *data)
{
	int		i;
	char	*temp;

	i = 0;
	while (data->parss.all[i])
	{
		if (!ft_strncmp(data->parss.all[i], "F", 1))
		{
			data->parss.floor = ft_strdup(data->parss.all[i]);
			temp = data->parss.all[i];
			data->parss.f_index = i;
			data->parss.all[i] = ft_strdup("");
			free(temp);
			return (0);
		}
		i++;
	}
	return (1);
}

int	get_ceiling(t_all *data)
{
	int		i;
	char	*temp;

	i = 0;
	while (data->parss.all[i])
	{
		if (!ft_strncmp(data->parss.all[i], "C", 1))
		{
			data->parss.ceiling = ft_strdup(data->parss.all[i]);
			temp = data->parss.all[i];
			data->parss.c_index = i;
			data->parss.all[i] = ft_strdup("");
			free(temp);
			return (0);
		}
		i++;
	}
	return (1);
}