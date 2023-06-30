/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:50:57 by muganiev          #+#    #+#             */
/*   Updated: 2023/06/29 16:51:00 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset( void *pointer, int value, size_t count )
{
	size_t			i;
	unsigned char	*ptr;

	ptr = pointer;
	i = 0;
	while (i < count)
	{
		*ptr = (unsigned char ) value;
		ptr++;
		i++;
	}
	return (pointer);
}
