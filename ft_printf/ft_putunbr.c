
#include "ft_printf.h"

/*void	ft_putnr(unsigned int n)
{
	if (n < 10)
		ft_putchar(n + 48);
	if (n > 9)
	{
		ft_putnr(n / 10);
		ft_putchar((n % 10) + 48);
	}
}

int	ft_putunbr(int n)
{
	unsigned int	uint_max;

	uint_max = UINT_MAX;
	if (n < 0)
		ft_putnr(uint_max - (unsigned int)(-n) + 1);
	else
		ft_putnr((unsigned int)n);
}*/

int	ft_ulength(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		len;

	len = ft_ulength(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (n != 0)
	{
		str[len - 1] = n % 10 + 48;
		n /= 10;
		len--;
	}
	return (str);
}

int	ft_putunbr(unsigned int n)
{
	int		count;
	char	*str;

	count = 0;
	if (n == 0)
		count = write(1, "0", 1);
	else
	{
		str = ft_uitoa(n);
		count = ft_putstr(str);
		free(str);
	}
	return (count);
}
