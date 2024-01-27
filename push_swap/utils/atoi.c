#include "../push_swap.h"

int ft_atoi(char *s)
{
    int i;
    int sign;
    int res;

    i = 0;
    sign = 1;
    res = 0;
    while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\v' || s[i] == '\r' || s[i] == '\f')
        i++;
    if (s[i] == '-')
        sign = -1;
    if (s[i] == '-' || s[i] == '+')
        i++;
    while (s[i] >= '0' && s[i] <= '9')
    {
        res = res * 10 + s[i] - '0';
        i++;
    }
    return (res * sign);
}