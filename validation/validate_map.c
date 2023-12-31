/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:56:01 by muganiev          #+#    #+#             */
/*   Updated: 2023/06/30 14:54:52 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	validate_map(t_all *data)
{
	init_map(data);
	add_space(data);
	if (check_characters(data))
	{
		free_maps(data);
		printf("invalid map characters\n");
		return (1);
	}
	if (check_valid_map(data))
	{
		free_maps(data);
		printf("invalid map \n");
		return (1);
	}
	init_angle(data);
	return (0);
}
