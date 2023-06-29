/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:42:04 by muganiev          #+#    #+#             */
/*   Updated: 2023/06/29 18:42:06 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	horizontal_inter_helper(t_all *data, double ang, \
		int *index_x, int *index_y)
{
	if (is_up(ang))
	{
		*index_x = floor(data->norm.first_x / CUB);
		*index_y = floor((data->norm.first_y - 1) / CUB);
	}
	else
	{
		*index_x = floor(data->norm.first_x / CUB);
		*index_y = floor((data->norm.first_y) / CUB);
	}
}
