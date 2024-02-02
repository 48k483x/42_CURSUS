#include "../push_swap.h"

bool    integer_check(int *tab, int ac)
{
    int i;

    i = 0;
    while (i < ac)
    {
        if (tab[i] == INT_MIN || tab[i] > INT_MAX || tab[i] < INT_MIN)
            return (false);
        i++;
    }
    return (true);
}

bool is_valid_integer(int ac, char **av)
{
    int i, j;

    for (i = 1; i < ac; i++)
    {
        j = 0;
        while (av[i][j] == ' ' || (av[i][j] >= 9 && av[i][j] <= 13))
            j++;
        if (av[i][j] == '+' || av[i][j] == '-')
        {
            j++;
            if (av[i][j] == '\0')
                return false;
        }
        while (av[i][j] != '\0')
        {
            if (!ft_isdigit(av[i][j]))
                return false;
            j++;
        }
    }
    return true;
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

// bool double_Check(int *tab, int ac)
// {
//     int i;
//     int j;

//     i = 0;
//     while (i < ac)
//     {
//         j = i + 1;
//         while (j < ac)
//         {
//             printf("Comparing tab[%d] = %d with tab[%d] = %d\n", i, tab[i], j, tab[j]);
//             if (tab[i] == tab[j])
//             {
//                 printf("Found duplicate: %d\n", tab[i]);
//                 return (false);
//             }
//             j++;
//         }
//         i++;
//     }
//     printf("No duplicates found\n");
//     return (true);  
// }

bool    input_check(int ac, int *tab)
{
    if (ac < 3)
        exit_with_message("Error\n");
    if (!integer_check(tab, ac - 1))
    {
        free(tab);
        exit_with_message("Error\n");
    }
    if (!double_Check(tab, ac - 1))
    {
        free(tab);
        exit_with_message("Error Dup\n");
    }
    return (true);
}
