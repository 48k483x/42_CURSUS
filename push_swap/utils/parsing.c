
#include "../push_swap.h"

char ***_parsed_av(int ac, char **av)
{
	char ***tab;
	int i;

	tab = malloc(sizeof(char **) * (ac + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		tab[i] = ft_split(av[i + 1], ' ');
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
void free_triple_array(char ***tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			free(tab[i][j]);
			j++;
		}
		free(tab[i]);
		i++;
	}
	free(tab);
}
int _parsed_array_num(char ***tab)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			j++;
			count++;
		}
		i++;
	}
	return (count);
}

char **_parsed_arr(char ***tab)
{
	char **arr;
	int i;
	int j;
	int k;

	arr = malloc(sizeof(char *) * (_parsed_array_num(tab) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	k = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			arr[k] = strdup(tab[i][j]);
			j++;
			k++;
		}
		i++;
	}
	free_triple_array(tab);
	arr[k] = NULL;
	return (arr);
}
