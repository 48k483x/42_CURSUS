
#include "libft.h"

char	*mallo(void)
{
	char	*str;

	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;
	size_t			total_lenght;
	char			*sub;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	total_lenght = ft_strlen(s);
	if ((start >= total_lenght) || len == 0)
		return (mallo());
	if (total_lenght < (start + len))
		len = total_lenght - start;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (i < total_lenght && j < len)
	{
		sub[j] = s[i + start];
		i++;
		j++;
	}
	sub[j] = '\0';
	return (sub);
}
