
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	lenght;

	lenght = ft_strlen((char *)s) + 1;
	dup = malloc(sizeof(char) * lenght);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, lenght);
	return (dup);
}
