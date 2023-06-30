/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:13:22 by muganiev          #+#    #+#             */
/*   Updated: 2023/06/24 23:45:04 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	check_file_for_reading(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("something wrong with your file, it can not be oppened\n");
		close(fd);
		exit(1);
	}
	return (fd);
}

int	count_file_lines(char *file)
{
	int		i;
	char	*str;
	int		fd;

	i = 0;
	fd = check_file_for_reading(file);
	if (fd == -3)
		return (1);
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	return (i);
}

void	init_data(t_all *data)
{
	data->parss.all = NULL;
	data->parss.ceiling = NULL;
	data->parss.floor = NULL;
	data->parss.south = NULL;
	data->parss.north = NULL;
	data->parss.east = NULL;
	data->parss.west = NULL;
}

int	validate_file_extension(char *file_name)
{
	char			*extension;
	unsigned int	required_len;

	required_len = 3;
	extension = ft_strchr(file_name, '.');
	if (!extension)
		return (1);
	if (ft_strlen(extension + 1) > required_len)
		required_len = ft_strlen(extension + 1);
	if (ft_strncmp(extension + 1, "cub", required_len))
		return (1);
	return (0);
}

int	read_file(char *file, t_all *data, int i)
{
	int		fd;
	int		len;
	char	*line;
	char	*trimed_line;

	len = count_file_lines(file);
	data->len = len;
	fd = check_file_for_reading(file);
	if (fd == -3 || len < 1)
		return (0);
	data->parss.all = malloc(sizeof(char *) * (len + 1));
	if (!data->parss.all)
		return (0);
	line = get_next_line(fd);
	trimed_line = ft_strtrim(line, "\n");
	while (line)
	{
		data->parss.all[i] = trimed_line;
		free(line);
		line = get_next_line(fd);
		trimed_line = ft_strtrim(line, "\n");
		i++;
	}
	data->parss.all[i] = NULL;
	return (1);
}
