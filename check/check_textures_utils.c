

#include "../include/include.h"

int	check_is_white_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && !(str[i] >= 9 && str[i] <= 13))
			return (i);
		i++;
	}
	return (i);
}

int	open_file(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (1);
	return (0);
}

void	init_textures(t_all *data)
{
	data->valid.ea = NULL;
	data->valid.we = NULL;
	data->valid.so = NULL;
	data->valid.no = NULL;
}
