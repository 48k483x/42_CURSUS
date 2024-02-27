
#include "ft_printf.h"

int	ft_putstr(char *s)
{
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}	
	else
	{
		write(1, s, ft_strlen(s));
		return (ft_strlen(s));
	}
}
