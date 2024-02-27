
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*m;
	unsigned char	*p;
	size_t			i;

	m = (unsigned char *)s1;
	p = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (m[i] != p[i])
			return ((int)(m[i] - p[i]));
		i++;
	}
	return (0);
}
