/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:01:36 by muganiev          #+#    #+#             */
/*   Updated: 2023/06/29 17:01:39 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	free_metadata(t_all *data)
{
	free(data->parss.east);
	free(data->parss.west);
	free(data->parss.north);
	free(data->parss.south);
	free(data->parss.ceiling);
	free(data->parss.floor);
}

void	free_rgb(char **rgb)
{
	int	i;

	i = 0;
	while (rgb[i])
		free(rgb[i++]);
	free(rgb);
}

void	free_textures(t_all *data)
{
	free(data->valid.ea);
	free(data->valid.we);
	free(data->valid.so);
	free(data->valid.no);
}

void	free_map(t_all *data)
{
	int	i;

	i = 0;
	while (data->parss.map[i])
		free(data->parss.map[i++]);
	free(data->parss.map);
}

void	free_maps(t_all *data)
{
	int	i;

	i = 0;
	while (data->valid.maps[i])
		free(data->valid.maps[i++]);
	free(data->valid.maps);
}
