/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:01:47 by muganiev          #+#    #+#             */
/*   Updated: 2023/06/29 17:01:49 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	free_all(t_all *data)
{
	int	i;

	i = 0;
	while (data->parss.all[i])
		free(data->parss.all[i++]);
	free(data->parss.all);
}
