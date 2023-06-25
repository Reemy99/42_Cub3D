/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:13:22 by muganiev          #+#    #+#             */
/*   Updated: 2023/06/24 23:15:58 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	check_is_map_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= 9 && str[i] <= 13) || (str[i] == ' ')))
			return (1);
		i++;
	}
	return (0);
}

int	get_info_of_map(t_all *data)
{
	if (parse_ceiling(data))
		return (0);
	if (parse_floor(data))
		return (0);
	if (parse_north(data))
		return (0);
	if (parse_south(data))
		return (0);
	if (parse_east(data))
		return (0);
	if (parse_west(data))
		return (0);
	return (1);
}

void	save_map(t_all *data, int i, int len, int temp)
{
	i = data->parss.map_index;
	while (data->parss.all[i] && !check_is_map_empty(data->parss.all[i]))
		i++;
	if (data->parss.all[i] == NULL)
	{
		data->parss.map = NULL;
		free_all(data);
		return ;
	}
	temp = i;
	while (data->parss.all[i] != NULL)
	{
		i++;
		len++;
	}
	data->parss.map = malloc(sizeof(char *) * (len + 1));
	i = 0;
	while (data->parss.all[temp] != NULL)
	{
		data->parss.map[i] = ft_strdup(data->parss.all[temp]);
		temp++;
		i++;
	}
	data->parss.map[i] = NULL;
	free_all(data);
}
