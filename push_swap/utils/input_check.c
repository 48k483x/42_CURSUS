#include "../push_swap.h"

bool    integer_check(int *tab, int ac)
{
    int i;

    i = 0;
    while (i < ac)
    {
        if (!(tab[i] < 2147483647 || tab[i] > -2147483648))
            exit_with_message("Error\n");
        i++;
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
                exit_with_message("Error\n");
            j++;
        }
        i++;
    }
    return (true);  
}

bool    input_check(int ac, int *tab)
{
    if (ac < 3)
        exit(1);
    if (!integer_check(tab, ac))
    {
        free(tab);
        exit_with_message("Error\n");
    }
    if (!double_Check(tab, ac))
    {
        free(tab);
        exit_with_message("Error\n");
    }
    return (true);
}
