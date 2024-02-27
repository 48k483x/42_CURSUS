
#include "ft_printf.h"

size_t	num_length(long num)
{
	size_t	len;

	len = 1;
	if (num < 0)
	{
		len++;
		num = -num;
	}
	while (num > 9)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	sign;
	long	num;
	size_t	len;
	char	*result;

	num = n;
	len = num_length(num);
	sign = 0;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	if (num < 0)
	{
		sign = 1;
		num = -num;
	}
	while (len-- > sign)
	{
		result[len] = (num % 10) + '0';
		num /= 10;
	}
	if (sign)
		result[0] = '-';
	return (result);
}

int	ft_putnbr(int nb)
{
	int		len;
	char	*num;

	num = ft_itoa(nb);
	len = ft_putstr(num);
	free(num);
	return (len);
}
