
#include "libft.h"

int	ft_isprint( int character )
{
	if (character >= ' ' && character <= 126)
		return (1);
	else
		return (0);
}
