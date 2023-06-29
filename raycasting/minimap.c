/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:42:18 by muganiev          #+#    #+#             */
/*   Updated: 2023/06/29 18:42:19 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

// the size of the player is 3 pixels
void	draw_miniplayer(t_all *data, double x, double y, int color)
{
	int	i;
	int	j;

	i = y - 1;
	while (++i < y + 3)
	{
		j = x - 1;
		while (++j < x + 3)
		{
			if (i >= 0 && j >= 0 && i < 200 && j < 200)
				my_mlx_pixel_put(data, j, i, color);
		}
	}
}
//________________________________________________________________
// Chec; if the current pixel inside the minimap and draw pixel by pixel with color
void	draw_inside_circle(t_all *data, double y, double x, int color)
{
	int	i;
	int	j;

	i = y - 1;
	while (++i < y + CUB)
	{
		j = x - 1;
		while (++j < x + CUB)
		{
			if (i >= 0 && j >= 0 && i < 200 && j < 200)
				if (sqrt(powf(i / 12.5 - 8, 2) + powf(j / 12.5 - 8, 2)) < 8)
					my_mlx_pixel_put(data, j, i, color);
		}
	}
}
//________________________________________________________________
void	render_minimap(t_all *data)
{
	int		i;
	int		j;
	double	dx;
	double	dy;	

	dx = data->x_player - 150;
	dy = data->y_player - 150;
	i = -1;
	while (data->valid.maps[++i])
	{
		j = -1;
		while (data->valid.maps[i][++j])
		{
			if (data->valid.maps[i][j] == '1')
				draw_inside_circle(data, (i * CUB - dy), \
				(j * CUB - dx), 0x000000);
		}
	}
	draw_miniplayer(data, (data->x_player - dx - 1), \
	(data->y_player - dy - 1), 0xff0000);
}
