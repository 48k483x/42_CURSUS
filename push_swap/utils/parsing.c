#include "../push_swap.h"

char     ***parsed_av(int ac, char **av)
{
    char ***tab;
    int i;

    tab = malloc(sizeof(char **) * (ac + 1));
    if (!tab)
        return (NULL);
    i = 0;
    while (i < ac)
    {
        tab[i] = ft_split(av[i], ' ');
        i++;
    }
    return (tab);
}
