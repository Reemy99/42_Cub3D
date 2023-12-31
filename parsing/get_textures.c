/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:13:22 by muganiev          #+#    #+#             */
/*   Updated: 2023/06/24 23:17:31 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	parse_east(t_all *data)
{
	int		i;
	char	*temp;

	i = 0;
	while (data->parss.all[i] != NULL)
	{
		if (!ft_strncmp(data->parss.all[i], "EA", 2))
		{
			data->parss.east = ft_strdup(data->parss.all[i]);
			temp = data->parss.all[i];
			data->parss.e_index = i;
			data->parss.all[i] = ft_strdup("");
			free(temp);
			return (0);
		}
		i++;
	}
	return (1);
}

int	parse_west(t_all *data)
{
	int		i;
	char	*temp;

	i = 0;
	while (data->parss.all[i] != NULL)
	{
		if (!ft_strncmp(data->parss.all[i], "WE", 2))
		{
			data->parss.west = ft_strdup(data->parss.all[i]);
			temp = data->parss.all[i];
			data->parss.w_index = i;
			data->parss.all[i] = ft_strdup("");
			free(temp);
			return (0);
		}
		i++;
	}
	return (1);
}

int	parse_south(t_all *data)
{
	int		i;
	char	*temp;

	i = 0;
	while (data->parss.all[i] != NULL)
	{
		if (!ft_strncmp(data->parss.all[i], "SO", 2))
		{
			data->parss.south = ft_strdup(data->parss.all[i]);
			temp = data->parss.all[i];
			data->parss.s_index = i;
			data->parss.all[i] = ft_strdup("");
			free(temp);
			return (0);
		}
		i++;
	}
	return (1);
}

int	parse_north(t_all *data)
{
	int		i;
	char	*temp;

	i = 0;
	while (data->parss.all[i] != NULL)
	{
		if (!ft_strncmp(data->parss.all[i], "NO", 2))
		{
			data->parss.north = ft_strdup(data->parss.all[i]);
			temp = data->parss.all[i];
			data->parss.n_index = i;
			data->parss.all[i] = ft_strdup("");
			free(temp);
			return (0);
		}
		i++;
	}
	return (1);
}
