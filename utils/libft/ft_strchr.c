/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:51:22 by muganiev          #+#    #+#             */
/*   Updated: 2023/06/29 16:51:24 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	size;

	i = 0;
	size = (int)ft_strlen(s) + 1;
	while (i < size)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
		i++;
	}
	return (NULL);
}
