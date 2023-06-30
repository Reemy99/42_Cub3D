/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:41:54 by muganiev          #+#    #+#             */
/*   Updated: 2023/06/30 14:38:55 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	complete_drawing1(t_all *data, double *x1, double *y1)
{
	horizontal_inter(data, data->norm.start_angle);
	vertical_inter(data, data->norm.start_angle);
	if (calculate_distance(data, data->ver_y, data->ver_x) > \
	calculate_distance(data, data->hor_y, data->hor_x))
	{
		*y1 = data->hor_y;
		*x1 = data->hor_x;
		data->x_offset = fmod(*x1, CUB);
		if (is_up(data->norm.start_angle))
			data->norm.choiceast_txt = &data->north_txt;
		else
			data->norm.choiceast_txt = &data->south_txt;
	}
	else
	{
		*y1 = data->ver_y;
		*x1 = data->ver_x;
		data->x_offset = fmod(*y1, CUB);
		if (is_left(data->norm.start_angle))
			data->norm.choiceast_txt = &data->east_txt;
		else
			data->norm.choiceast_txt = &data->west_txt;
	}
}

//_____________________________________________________________

void	complete_drawing2(t_all *data, int i)
{
	int	j;

	j = 0;
	while (j < data->norm.start)
	{
		my_mlx_pixel_put(data, i, j, ceiling_color(data));
		j++;
	}
	while (j < data->norm.end)
	{
		data->norm.color = get_color(*data->norm.choiceast_txt, j, data, \
				data->norm.wall_height);
		my_mlx_pixel_put(data, i, j, data->norm.color);
		j++;
	}
	while (j < data->mlx.h_win)
	{
		my_mlx_pixel_put(data, i, j, floor_color(data));
		j++;
	}
}

//_____________________________________________________________
/*  calculates the start angle by subtracting 30 degrees from 
direction_ang and assigns the result to start_angle
convert from degree to π :
angle - (30 * (M_PI / 180)) -> angle - (30 * 0.01745) = 0.5235π -> 29.9999 degree
*/

void	calculate_angle(t_all *data, double *increment)
{
	data->norm.start_angle = data->direction_ang - (30 * (M_PI / 180));
	data->norm.start_angle = normalize_angle(data->norm.start_angle);
	*increment = (60 * (M_PI / 180)) / data->mlx.w_win;
}

//_____________________________________________________________
// player angle

int	start_drawing(t_all *data)
{
	int				i;
	double			x1;
	double			y1;
	double			increment;

	calculate_angle(data, &increment);
	i = -1;
	while (++i < data->mlx.w_win)
	{
		complete_drawing1(data, &x1, &y1);
		data->norm.cub_distance = calculate_distance(data, y1, x1) / CUB;
		data->norm.cub_distance *= cos(data->direction_ang - \
				data->norm.start_angle);
		data->norm.wall_height = data->mlx.h_win / data->norm.cub_distance;
		data->norm.start = (data->mlx.h_win / 2) - (data->norm.wall_height / 2);
		if (data->norm.start < 0)
			data->norm.start = 0;
		data->norm.end = (data->mlx.h_win / 2) + (data->norm.wall_height / 2);
		if (data->norm.end > data->mlx.h_win || data->norm.end < 0)
			data->norm.end = data->mlx.h_win;
		complete_drawing2(data, i);
		data->norm.start_angle += increment;
	}
	return (0);
}

//_____________________________________________________________
//all the textures
// minimap photo sized

int	start_game(t_all *data)
{
	start_drawing(data);
	render_minimap(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, \
			data->minimap.img, -20, -20);
	return (0);
}
