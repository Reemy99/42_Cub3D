

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
