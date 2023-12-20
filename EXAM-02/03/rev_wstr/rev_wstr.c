#include <unistd.h>

void
rev_wstr(char *s, int first)
{
	int i = 0; int start;

	if (s[i])
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t'))
			i++;
		if (!s[i])
			return ;
		start = i;
		while (s[i] && s[i] != ' ' && s[i] != '\t')
			i++;
		rev_wstr(&s[i], 0);
		write (1, &s[start], i - start);
		if (!first)
			write (1, " ", 1);
	}
}

int
main(int ac, char **av)
{
	if (ac == 2)
		rev_wstr(av[1], 1);
	write (1, "\n", 1);
}
