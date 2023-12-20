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
int
main(int ac, char **av)
{
	if (ac == 2)
		printf("%d\n", count_words(av[1]));
}
