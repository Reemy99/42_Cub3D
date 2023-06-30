/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:13:22 by muganiev          #+#    #+#             */
/*   Updated: 2023/06/25 17:14:20 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/include.h"

int	check(t_all *data)
{
	if (validate_rgb_colors(data))
		return (1);
	if (validate_textures(data))
	{
		free_map(data);
		free_textures(data);
		return (1);
	}
	if (validate_map(data))
	{
		free_textures(data);
		return (1);
	}
	return (0);
}

//_________________________________________________________________________

int	check_wall(t_all *data, double y, double x)
{
	int	x_wall;
	int	y_wall;

	x_wall = x / CUB;
	y_wall = y / CUB;
	data->x_p_pos = data->x_player / CUB;
	data->y_p_pos = data->y_player / CUB;
	if (data->valid.maps[(int)y_wall][(int)x_wall] == '1')
		return (1);
	if (check_wall_x(data, x_wall, y_wall) == 1)
		return (1);
	if (check_wall_y(data, x_wall, y_wall) == 1)
		return (1);
	return (0);
}

//_________________________________________________________________________
//fmod helps to divide one number by another and gives you the remainder

double	normalize_angle(double ang)
{
	ang = fmod(ang, 2 * M_PI);
	if (ang < 0)
		ang += 2 * M_PI;
	return (ang);
}

//_________________________________________________________________________

int	main(int ac, char **av)
{
	t_all	data;

	if (ac != 2)
	{
		printf("Usage : ./Cub3D /maps/<map name>\n");
		exit(1);
	}
	else
	{
		if (!parsing(av[1], &data))
			return (1);
		if (check(&data))
			return (1);
		init_mlx(&data);
		start_game(&data);
		mlx_hook(data.mlx.win, DESTROY, 0, mlx_close, &data);
		mlx_hook(data.mlx.win, KEY_RELEASE, 0, mlx_keyrelease, &data);
		mlx_hook(data.mlx.win, KEY_PRESS, 0, mlx_key, &data);
		mlx_loop_hook(data.mlx.mlx, mlx_keypress, &data);
		mlx_loop(data.mlx.mlx);
		return (0);
	}	
	return (0);
}
