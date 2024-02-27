
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				s_len;
	unsigned char	p;

	s_len = ft_strlen(s);
	p = (unsigned char)c;
	while (s_len >= 0)
	{
		if (s[s_len] == p)
			return ((char *)&s[s_len]);
		s_len--;
	}
	return (NULL);
}
