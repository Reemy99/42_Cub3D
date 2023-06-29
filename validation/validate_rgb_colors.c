/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_rgb_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:16:32 by muganiev          #+#    #+#             */
/*   Updated: 2023/06/29 17:16:34 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	check_floor(t_all *data, int j)
{
	char	**rgb;
	char	*trimed_str;

	if (data->parss.floor[1] != ' ')
		return (0);
	trimed_str = ft_strtrim(&data->parss.floor[1], " ");
	j = count_commas(trimed_str);
	if (j == 2)
	{
		rgb = ft_split(trimed_str, ',');
		free(trimed_str);
		if (check_rgb_validity(rgb))
		{
			free_rgb(rgb);
			return (0);
		}
		if (fill_floor_color(rgb, data))
		{
			free_rgb(rgb);
			return (0);
		}
		free_rgb(rgb);
		return (1);
	}
	return (0);
}

int	check_ceiling(t_all *data, int j)
{
	char	**rgb;
	char	*trimed_str;

	if (data->parss.ceiling[1] != ' ')
		return (0);
	trimed_str = ft_strtrim(&data->parss.ceiling[1], " ");
	j = count_commas(trimed_str);
	if (j == 2)
	{
		rgb = ft_split(trimed_str, ',');
		free(trimed_str);
		if (check_rgb_validity(rgb))
		{
			free_rgb(rgb);
			return (0);
		}
		if (fill_ceiling_color(rgb, data))
		{
			free_rgb(rgb);
			return (0);
		}
		free_rgb(rgb);
		return (1);
	}
	return (0);
}

int	validate_rgb_colors(t_all *data)
{
	if (!check_ceiling(data, 0))
	{
		free_map(data);
		free_parsing_data(data);
		printf("check ceiling\n");
		return (1);
	}
	if (!check_floor(data, 0))
	{
		free_map(data);
		free_parsing_data(data);
		printf("check floor\n");
		return (1);
	}
	free(data->parss.floor);
	free(data->parss.ceiling);
	return (0);
}
