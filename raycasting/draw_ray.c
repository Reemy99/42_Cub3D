/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:25:06 by realdahh          #+#    #+#             */
/*   Updated: 2023/06/30 14:25:09 by realdahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

unsigned int	get_color(t_texture txt, double y, t_all *data, double wall_h)
{
	int				y_offset;
	unsigned int	color;
	int				x_offset;

	y_offset = y + (wall_h / 2) - (data->mlx.h_win / 2);
	x_offset = (data->x_offset / CUB) * txt.width;
	y_offset = ((y_offset) * ((double)txt.height / \
				wall_h));
	color = txt.addr[abs((y_offset * txt.height) + x_offset)];
	return ((unsigned int)color);
}

void	player_position(t_all *data, int x, int y, int *player)
{
	data->valid.player = data->valid.maps[y][x];
	data->y_player = (y * CUB) + (CUB / 2);
	data->x_player = (x * CUB) + (CUB / 2);
	data->valid.maps[(int)roundf(y)][(int)roundf(x)] = '0';
	*player = *player + 1;
}
