/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_rgb_colors_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:16:15 by muganiev          #+#    #+#             */
/*   Updated: 2023/07/01 14:44:40 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	check_rgb_validity(char **rgb)
{
	int	i;
	int	j;
	int	number;

	i = 0;
	while (rgb[i])
	{
		j = 0;
		number = ft_atoi(rgb[i]);
		if (!(number >= 0 && number <= 255))
			return (1);
		while (rgb[i][j])
		{
			if (!ft_isdigit(rgb[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	count_commas(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ',')
			j++;
		i++;
	}
	return (j);
}

int	fill_floor_color(char **color, t_all *data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (!color[i])
			return (1);
		data->valid.floor[i] = ft_atoi(color[i]);
		i++;
	}
	return (0);
}

int	fill_ceiling_color(char **color, t_all *data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (!color[i])
			return (1);
		data->valid.ceiling[i] = ft_atoi(color[i]);
		i++;
	}
	return (0);
}
