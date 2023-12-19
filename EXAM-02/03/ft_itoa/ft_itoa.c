#include <stdlib.h>

int lent(int n)
{
	int len = 0;

	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n/=10;
	}
	return (len);
}

char *ft_itoa(int nbr)
{
	int len = lent(nbr); int sign = 1; unsigned int num;
	char *s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s[len--] = '\0';
	if (nbr == 0)
		s[0] = '0';
	if (nbr < 0)
	{
		sign = -sign;
		num = -nbr;
		s[0] = '-';
	}
	else
		num = nbr;
	while (num > 0)
	{
		s[len] = 48 + (num % 10);
		num/=10;
		len--;
	}
	return (s);
}
#include <stdio.h>
int main ()
{
	printf("This is the string  --> %s", ft_itoa(20040905));
}
