/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:03:19 by realdahh          #+#    #+#             */
/*   Updated: 2023/06/30 14:03:21 by realdahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	my_mlx_pixel_put(t_all *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->mlx.addr + (y * data->mlx.line_length + x * (data->mlx.bpp
				/ 8));
	*(unsigned int *)dst = color;
}
//______________________________________
//loading textuers for all (E, W, S, N and Minimap)
void	load_textures(t_all *data)
{
	data->east_txt.img = mlx_xpm_file_to_image(data->mlx.mlx, data->valid.ea, \
	&data->east_txt.width, &data->east_txt.height);
	if (!data->east_txt.img)
		exit(1);
	data->east_txt.addr = (int *) mlx_get_data_addr(data->east_txt.img, \
	&data->east_txt.bpp, &data->east_txt.line_length, &data->east_txt.endian);
	data->west_txt.img = mlx_xpm_file_to_image(data->mlx.mlx, data->valid.we, \
	&data->west_txt.width, &data->west_txt.height);
	if (!data->west_txt.img)
		exit(1);
	data->west_txt.addr = (int *) mlx_get_data_addr(data->west_txt.img, \
	&data->west_txt.bpp, &data->west_txt.line_length, &data->west_txt.endian);
	data->north_txt.img = mlx_xpm_file_to_image(data->mlx.mlx, data->valid.no, \
	&data->north_txt.width, &data->north_txt.height);
	if (!data->north_txt.img)
		exit(1);
	data->north_txt.addr = (int *) mlx_get_data_addr(data->north_txt.img, \
	&data->north_txt.bpp, &data->north_txt.line_length, &data->north_txt.endian);
	data->south_txt.img = mlx_xpm_file_to_image(data->mlx.mlx, data->valid.so, \
	&data->south_txt.width, &data->south_txt.height);
	if (!data->south_txt.img)
		exit(1);
data->minimap.img = mlx_xpm_file_to_image(data->mlx.mlx, \
			"./textures/minimap.xpm", &data->minimap.width, \
			&data->minimap.height);
	if (!data->minimap.img)
		exit(1);
	data->south_txt.addr = (int *) mlx_get_data_addr(data->south_txt.img, \
	&data->south_txt.bpp, &data->south_txt.line_length, &data->south_txt.endian);
}

void	init_mlx(t_all *data)
{
	data->mlx.mlx = mlx_init();
	data->mlx.w_win = 2560 / 2;
	data->mlx.h_win = 1440 / 2;
	data->mlx.win = mlx_new_window(data->mlx.mlx, data->mlx.w_win, \
	data->mlx.h_win, "Cub3D");
	data->mlx.img = mlx_new_image(data->mlx.mlx, data->mlx.w_win, \
	data->mlx.h_win);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img, &data->mlx.bpp,
			&data->mlx.line_length, &data->mlx.endian);
	//ft_bzero(&data->key, sizeof(data->key));
	load_textures(data);
}
