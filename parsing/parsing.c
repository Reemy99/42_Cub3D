/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:13:22 by muganiev          #+#    #+#             */
/*   Updated: 2023/06/25 17:14:20 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	check_duplicate_metadata(t_all *data)
{
	int	i;

	i = 0;
	while (data->parss.all[i])
	{
		if (!ft_strncmp(data->parss.all[i], "SO", 2))
			return (0);
		if (!ft_strncmp(data->parss.all[i], "NO", 2))
			return (0);
		if (!ft_strncmp(data->parss.all[i], "WE", 2))
			return (0);
		if (!ft_strncmp(data->parss.all[i], "EA", 2))
			return (0);
		if (!ft_strncmp(data->parss.all[i], "F", 1))
			return (0);
		if (!ft_strncmp(data->parss.all[i], "C", 1))
			return (0);
		i++;
	}
	return (1);
}

int	check_map_position(t_all *data)
{
	int	i;

	i = 0;
	while (data->parss.all[i])
	{
		if (ft_strlen(data->parss.all[i]))
			break ;
		i++;
	}
	data->parss.map_index = i;
	if (data->parss.map_index < data->parss.c_index)
		return (0);
	if (data->parss.map_index < data->parss.f_index)
		return (0);
	if (data->parss.map_index < data->parss.w_index)
		return (0);
	if (data->parss.map_index < data->parss.e_index)
		return (0);
	if (data->parss.map_index < data->parss.s_index)
		return (0);
	if (data->parss.map_index < data->parss.n_index)
		return (0);
	return (1);
}

int	check_map_and_file(char *av, t_all *data)
{
	init_data(data);
	if (validate_file_extension(av))
		return (printf("check your file extension\n"), 0);
	if (!read_file(av, data, 0))
	{
		printf("I guess your file is empty bro\n");
		return (0);
	}
	if (!get_info_of_map(data))
	{
		free_all(data);
		free_metadata(data);
		printf("check your map, some of the map inputs are missing \n");
		return (0);
	}
	if (!check_duplicate_metadata(data))
	{
		free_all(data);
		free_metadata(data);
		printf("Broooo, you have duplicate map input\n");
		return (0);
	}
	return (1);
}

void	free_parsing_data(t_all *data)
{
	free(data->parss.floor);
	free(data->parss.ceiling);
	free(data->parss.east);
	free(data->parss.west);
	free(data->parss.north);
	free(data->parss.south);
}

int	parsing(char *av, t_all *data)
{
	if (!check_map_and_file(av, data))
		return (0);
	if (!check_map_position(data))
	{
		free_all(data);
		free_metadata(data);
		printf("map is above a metadata");
		return (0);
	}
	save_map(data, 0, 0, 0);
	if (!data->parss.map)
	{
		free_parsing_data(data);
		printf("missing map\n");
		return (0);
	}
	return (1);
}
