/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:03:19 by realdahh          #+#    #+#             */
/*   Updated: 2023/06/30 19:43:08 by realdahh         ###   ########.fr       */
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

void	load_minimap_txt(t_all *data)
{
	data->minimap.img = mlx_xpm_file_to_image(data->mlx.mlx, \
		"./textures/minimap.xpm", &data->minimap.width, \
		&data->minimap.height);
	if (!data->minimap.img)
		exit(1);
}

//______________________________________

void	load_textures(t_all *data)
{
	load_minimap_txt(data);
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
	data->north_t.img = mlx_xpm_file_to_image(data->mlx.mlx, data->valid.no, \
	&data->north_t.width, &data->north_t.height);
	if (!data->north_t.img)
		exit(1);
	data->north_t.addr = (int *) mlx_get_data_addr(data->north_t.img, \
	&data->north_t.bpp, &data->north_t.line_length, &data->north_t.endian);
	data->south_t.img = mlx_xpm_file_to_image(data->mlx.mlx, data->valid.so, \
	&data->south_t.width, &data->south_t.height);
	if (!data->south_t.img)
		exit(1);
	data->south_t.addr = (int *) mlx_get_data_addr(data->south_t.img, \
	&data->south_t.bpp, &data->south_t.line_length, &data->south_t.endian);
}

//____________________________________________________

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
	ft_bzero(&data->key, sizeof(data->key));
	load_textures(data);
}
