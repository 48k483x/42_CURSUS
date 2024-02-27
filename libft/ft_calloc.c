
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memory;
	size_t	total_size;

	total_size = nmemb * size;
	memory = malloc(total_size);
	if (memory != NULL)
		ft_memset(memory, 0, total_size);
	return (memory);
}
