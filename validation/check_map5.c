/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:56:22 by muganiev          #+#    #+#             */
/*   Updated: 2023/06/29 17:52:43 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	check_wall_y(t_all *data, int x_wall, int y_wall)
{
	if (x_wall != data->x_p_pos && y_wall != data->y_p_pos)
	{
		if (y_wall -1 == -1 || x_wall - 1 == -1)
			return (1);
		if (data->valid.maps[y_wall][x_wall - 1] == '1' \
		&& data->valid.maps[y_wall - 1][x_wall] == '1')
			return (1);
	}
	if (x_wall != data->x_p_pos && y_wall != data->y_p_pos)
	{
		if (y_wall - 1 == -1 || x_wall + 1 == data->valid.line_len)
			return (1);
		if (data->valid.maps[y_wall][x_wall + 1] == '1' \
		&& data->valid.maps[y_wall - 1][x_wall] == '1')
			return (1);
	}
	return (0);
}

int	check_wall_x(t_all *data, int x_wall, int y_wall)
{
	if (x_wall != data->x_p_pos && y_wall != data->y_p_pos)
	{
		if (y_wall + 1 == data->valid.map_len || x_wall - 1 == -1)
			return (1);
		if (data->valid.maps[y_wall][x_wall - 1] == '1' \
		&& data->valid.maps[y_wall + 1][x_wall] == '1')
			return (1);
	}
	if (x_wall != data->x_p_pos && y_wall != data->y_p_pos)
	{
		if (y_wall + 1 == data->valid.map_len \
		|| x_wall + 1 == data->valid.line_len)
			return (1);
		if (data->valid.maps[y_wall][x_wall + 1] == '1' \
		&& data->valid.maps[y_wall + 1][x_wall] == '1')
			return (1);
	}
	return (0);
}

int	zero_checker(t_all *data, int i, int j)
{
	if (data->valid.maps[i][j] == '0')
	{
		if (data->valid.maps[i][j - 1] == ' ')
			return (1);
		if (data->valid.maps[i][j + 1] == ' ')
			return (1);
		if (data->valid.maps[i - 1][j] == ' ')
			return (1);
		if (data->valid.maps[i + 1][j] == ' ')
			return (1);
	}
	return (0);
}

int	check_space(t_all *data, int i, int j)
{
	if (data->valid.maps[i][j] == ' ')
	{
		if (data->valid.maps[i][j - 1] != '1' && data->valid.maps[i][j
			- 1] != ' ')
			return (1);
		if (data->valid.maps[i][j + 1] != '1' && data->valid.maps[i][j
			+ 1] != ' ')
			return (1);
		if (data->valid.maps[i - 1][j] != '1' && data->valid.maps[i
			- 1][j] != ' ')
			return (1);
		if (data->valid.maps[i + 1][j] != '1' && data->valid.maps[i
			+ 1][j] != ' ')
			return (1);
	}
	return (0);
}
