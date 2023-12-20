#include <stdio.h>
#include <stdlib.h>

int count_words(char *s)
{
	int count = 0; int i = 0;

	if (s[i] == ' ' || s[i] == '\t')
		count--;
	while (s[i])
	{
		if ((s[i] == ' ' || s[i] == '\t') && (s[i+1] != ' ' || s[i+1] != '\t') && s[i+1] != '\0')
			count++;
		i++;
	}
	count++;
	return count;
}

char *malloc_words(char *s)
{
	char *word;
	int i = 0;
	while (s[i] && (s[i] != ' ' && s[i] != '\t'))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return NULL;
	i = 0;
	while (s[i] && (s[i] != ' ' && s[i] != '\t'))
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char    **ft_split(char *s)
{
	char **tab;
	int i;
	if (!s)
		return NULL;
	int words = count_words(s);
	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return NULL;
	i = 0;
	while (*s)
	{
		while (*s && (*s == ' ' || *s == '\t'))
			s++;
		if (*s && *s != ' ' && *s != '\t')
		{
			tab[i] = malloc_words(s);
			i++;
			while (*s && (*s != ' ' && *s != '\t'))
				s++;
		}
	}
	tab[i] = NULL;
	return tab;
}
int main(int ac, char **av)
{
    char **result = NULL;

    if (ac == 2)
        result = ft_split(av[1]); // Fix: use '=' instead of '=='

    int i = 0;

    while (result && result[i])
    {
        printf("%s\n", result[i]);
        free(result[i]); // Free the allocated memory for each word
        i++;
    }

    free(result); // Free the memory allocated for the array of words

    return 0;
}
