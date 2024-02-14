#include "../push_swap.h"

bool    integer_check(int *tab, int ac)
{
    int i;

    i = 0;
    while (i < ac)
    {
        if ( tab[i] > INT_MAX || tab[i] < INT_MIN)
            return (false);
        i++;
    }
    return (true);
}

bool is_valid_integer(int ac, char **av)
{
    int i, j;

    for (i = 0; i < ac; i++)
    {
            if (av[i] == NULL)
                return false;
        j = 0;
        while (av[i][j] != '\0' && (av[i][j] == ' ' || (av[i][j] >= 9 && av[i][j] <= 13)))
            j++;
        if (av[i][j] == '+' || av[i][j] == '-')
        {
            j++;
            if (av[i][j] == '\0')
                return (false);
        }
        while (av[i][j] != '\0')
        {
            if (!ft_isdigit(av[i][j]))
                return (false);
            j++;
        }
    }
    return (true);
}

bool   double_Check(int *tab, int ac)
{
    int i;
    int j;

    i = 0;
    while (i < ac)
    {
        j = i + 1;
        while (j < ac)
        {
            if (tab[i] == tab[j])
                return (false);
            j++;
        }
        i++;
    }
    return (true);  
}

bool    is_sorted(int *tab, int ac)
{
    int i;

    i = 0;
    while (i < ac)
    {
        if (i == ac - 1)
            break;
        else if (tab[i] > tab[i + 1])
            return (false);
        i++;
    }
    return (true);
}

bool    input_check(int ac, int *tab, stack **a, char **av)
{
    (void)a;
    if (ac < 2)
    {
        free(tab);
        exit(0);
    }
    if (is_sorted(tab, ac))
    {
        free(tab);
        free_split(av);
        exit(0);
    }
    if (!integer_check(tab, ac))
    {
        free(tab);
        free_split(av);
        exit_with_message("Error\n");
    }
    if (!double_Check(tab, ac))
    {
        free(tab);
        free_split(av);
        exit_with_message("Error Dup\n");
    }
    return (true);
}
