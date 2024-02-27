
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_lenght;
	size_t	indexes;

	src_lenght = ft_strlen(src);
	indexes = size - 1;
	i = 0;
	if (size == 0)
		return (src_lenght);
	while (i < indexes && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_lenght);
}
