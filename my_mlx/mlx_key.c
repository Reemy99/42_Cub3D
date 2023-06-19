/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reemaldahhan <reemaldahhan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:40:53 by zyacoubi          #+#    #+#             */
/*   Updated: 2023/06/18 13:36:43 by reemaldahha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	mlx_close(t_all *data)
{
	mlx_destroy_window(data->mlx.mlx, data->mlx.win);
	exit(0);
	return (1);
}

int	mlx_keyrelease(int keycode, t_all *data)
{
	if (keycode == UP)
		data->key.y = 0;
	else if (keycode == DOWN)
		data->key.y = 0;
	else if (keycode == LEFT)
		data->key.x = 0;
	else if (keycode == RIGHT)
		data->key.x = 0;
	else if (keycode == ROTATE_LEFT)
		data->key.pov = 0;
	else if (keycode == ROTATE_RIGHT)
		data->key.pov = 0;
	else if (keycode == ESC)
		exit(0);
	return (0);
}

int	mlx_key(int keycode, t_all *data)
{
	if (keycode == UP)
		data->key.y = 1;
	else if (keycode == DOWN)
		data->key.y = -1;
	else if (keycode == LEFT)
		data->key.x = 1;
	else if (keycode == RIGHT)
		data->key.x = -1;
	else if (keycode == ROTATE_LEFT)
		data->key.pov = 1;
	else if (keycode == ROTATE_RIGHT)
		data->key.pov = -1;
	else if (keycode == ESC)
		exit(0);
	return (0);
}

int	mlx_keypress(t_all *data)
{
	mlx_clear_window(data->mlx.mlx, data->mlx.win);
	if (data->key.pov == 1)
		rotate_left_and_right(data, 1);
	else if (data->key.pov == -1)
		rotate_left_and_right(data, 2);
	else if (data->key.y == 1)
		move_up(data);
	else if (data->key.y == -1)
		move_down(data);
	else if (data->key.x == 1)
		move_left(data);
	else if (data->key.x == -1)
		move_right(data);
	start_game(data);
	return (0);
}
