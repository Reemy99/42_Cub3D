/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:25:06 by realdahh          #+#    #+#             */
/*   Updated: 2023/07/01 17:54:57 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

//return the color of a specific pixel from a texture based on 
// the given parameters
// calculate the y_offset with screen center
// calculate the x-offset in the texture on the horizontal position
// Calculate the y-offset in the texture with vertical position and wall height

unsigned int	get_textures(t_texture txt, double y, t_all *data, double wal_h)
{
	int				y_offset;
	int				x_offset;
	unsigned int	color;

	y_offset = y + (wal_h / 2) - (data->mlx.h_win / 2);
	x_offset = (data->x_offset / CUB) * txt.width;
	y_offset = ((y_offset) * ((double)txt.height / \
				wal_h));
	color = txt.addr[abs((y_offset * txt.height) + x_offset)];
	return ((unsigned int)color);
}

//_____________________________________________________________

void	player_position(t_all *data, int x, int y, int *player)
{
	data->valid.player = data->valid.maps[y][x];
	data->y_player = (y * CUB) + (CUB / 2);
	data->x_player = (x * CUB) + (CUB / 2);
	data->valid.maps[(int)roundf(y)][(int)roundf(x)] = '0';
	*player = *player + 1;
}
