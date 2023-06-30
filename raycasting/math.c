/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:25:37 by realdahh          #+#    #+#             */
/*   Updated: 2023/06/30 14:25:39 by realdahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	is_up(double ang)
{
	if (ang >= M_PI && ang <= (2 * M_PI))
		return (1);
	return (0);
}

//__________________________________________

int	is_left(double ang)
{
	if (ang >= (M_PI / 2) && ang <= ((3 * M_PI) / 2))
		return (1);
	return (0);
}

//__________________________________________

unsigned int	floor_color(t_all *data)
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
	unsigned int	color_value;

	red = data->valid.floor[0];
	green = data->valid.floor[1];
	blue = data->valid.floor[2];
	color_value = (red << 16) + (green << 8) + blue;
	return (color_value);
}

//__________________________________________
// Pythagorean theorem "fethagorse"

double	calculate_distance(t_all *data, double y, double x)
{
	return (sqrt(pow(x - data->x_player, 2) + pow(y - data->y_player, 2)));
}

//__________________________________________

unsigned int	ceiling_color(t_all *data)
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
	unsigned int	color_value;

	red = data->valid.ceiling[0];
	green = data->valid.ceiling[1];
	blue = data->valid.ceiling[2];
	color_value = (red << 16) + (green << 8) + blue;
	return (color_value);
}
