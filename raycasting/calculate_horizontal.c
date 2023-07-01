/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:25:31 by realdahh          #+#    #+#             */
/*   Updated: 2023/07/01 13:08:35 by realdahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

//_____________________________________________________________

void	horizontal_inter_init(t_all *data, double ang)
{
	data->norm.first_y = floor(data->y_player / CUB) * CUB;
	if (!is_up(ang))
		data->norm.first_y += CUB;
	data->norm.first_x = ((data->norm.first_y - data->y_player) / \
			tan(ang)) + data->x_player;
	data->norm.step_y = CUB;
	if (is_up(ang))
		data->norm.step_y *= -1;
	data->norm.step_x = (CUB / tan(ang));
	if (!is_left(ang) && data->norm.step_x < 0)
		data->norm.step_x *= -1;
	if (is_left(ang) && data->norm.step_x > 0)
		data->norm.step_x *= -1;
}
//_____________________________________________________________

void	horizontal_inter(t_all *data, double ang)
{
	int		index_x;
	int		index_y;

	horizontal_inter_init(data, ang);
	horizontal_inter_helper(data, ang, &index_x, &index_y);
	while (index_y >= 0 && index_y < data->valid.map_len \
	&& index_x >= 0 && index_x < data->valid.line_len)
	{
		if (data->valid.maps[index_y][index_x] == '1')
		{
			data->hor_x = data->norm.first_x;
			data->hor_y = data->norm.first_y;
			return ;
		}
		data->norm.first_x += data->norm.step_x;
		data->norm.first_y += data->norm.step_y;
		horizontal_inter_helper(data, ang, &index_x, &index_y);
	}
	data->hor_y = INT_MAX;
	data->hor_x = INT_MAX;
	return ;
}