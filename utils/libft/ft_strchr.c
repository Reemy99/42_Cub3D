

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
