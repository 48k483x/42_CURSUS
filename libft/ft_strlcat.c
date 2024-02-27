
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_lenght;
	size_t	src_lenght;
	size_t	n;

	i = 0;
	j = 0;
	dst_lenght = ft_strlen(dst);
	src_lenght = ft_strlen(src);
	n = size - 1;
	if (size <= dst_lenght || size == 0)
		return (src_lenght + size);
	while (dst[i])
		i++;
	while (i < n && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst_lenght + src_lenght);
}
