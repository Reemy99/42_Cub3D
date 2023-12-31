/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:56:12 by muganiev          #+#    #+#             */
/*   Updated: 2023/06/30 14:54:41 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	str_space(char **dest, char *original, unsigned int b_len)
{
	char	*to_fill;
	int		len;
	int		diff;
	int		i;

	len = ft_strlen(original);
	diff = b_len - len;
	to_fill = malloc(sizeof(char) * (len + diff + 1));
	if (!to_fill)
		exit(1);
	i = 0;
	while (original[i])
	{
		to_fill[i] = original[i];
		i++;
	}
	while (diff)
	{
		to_fill[i] = ' ';
		i++;
		diff--;
	}
	to_fill[i] = '\0';
	*dest = to_fill;
}

void	add_space(t_all *data)
{
	char	**map;
	int		i;
	int		b_len;

	b_len = big_len(data);
	data->valid.line_len = b_len;
	i = 0;
	while (data->valid.maps[i])
		i++;
	map = malloc(sizeof(char *) * (i + 1));
	if (!map)
		return ;
	i = 0;
	while (data->valid.maps[i])
	{
		str_space(&map[i], data->valid.maps[i], b_len);
		free(data->valid.maps[i]);
		i++;
	}
	map[i] = NULL;
	free(data->valid.maps);
	data->valid.maps = map;
}

int	endmap_index(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (str[i])
	{
		if (ft_strlen(str[i]) && check_is_map_empty(str[i]))
			break ;
		i--;
	}
	return (i);
}
