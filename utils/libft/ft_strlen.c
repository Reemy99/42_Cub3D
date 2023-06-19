

#include "libft.h"

size_t	ft_strlen( const char *theString )
{
	unsigned int	i;

	i = 0;
	while (*theString++)
		i++;
	return (i);
}
