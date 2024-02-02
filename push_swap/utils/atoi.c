#include "../push_swap.h"

int ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int ft_atoi(char *nptr)
{
	int					i;
	int					sign;
	long int			num;

	i = 0;
	sign = 1;
	num = 0;
	 if (!nptr)
        exit_with_message("Error\n");
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		num *= 10;
		num += nptr[i] - '0';
		i++;
	}
	return (num * sign);
}

