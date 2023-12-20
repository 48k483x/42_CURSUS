/*#include <unistd.h>
#include <stdlib.h>

int skip_space(char *s)
{
	int i = 0;
	while (s[i] > 9 && s[i] < 13)
		i++;
	return i;
}

int count_first_word(char *s)
{
	int i = skip_space(s);
	while(s[i] && !(s[i] > 9 && s[i] < 13))
		i++;
	return (i);
}

int slen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

int main (int ac, char **av)
{
	if (ac == 2)
	{
		int buf_len = count_first_word(av[1]); int i = 0;
		char *buf = (char *)malloc(sizeof(char) * (buf_len + 1));
		char *s =   (char *)malloc(sizeof(char) * (slen(av[1] + 1)));
		if (!buf || !s)
			return (0);
		buf_len = skip_space(&av[1][buf_len]);
		while (av[1][buf_len])
		{
			if (av[1][buf_len] == ' ' || av[1][buf_len] == '\t')
			{
				s[i] = av[1][buf_len];
				while (av[1][buf_len] == ' ' || av[1][buf_len] == '\t')
					buf_len++;
			}
			s[i] = av[1][buf_len];
			buf_len++;
			i++;
		}
		s[i] = '\0';
		write(1, &s, slen(s));	
	}
	write (1, "\n", 1);
}
*/

/*
#include <unistd.h>
#include <stdlib.h>

int skip_space(char *s)
{
    int i = 0;
    while (s[i] && (s[i] == ' ' || (s[i] > 8 && s[i] < 14)))
        i++;
    return i;
}

int count_first_word(char *s)
{
    int i = skip_space(s);
    while (s[i] && !(s[i] == ' ' || (s[i] > 8 && s[i] < 14)))
        i++;
    return i;
}

int slen(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return i;
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int buf_len = count_first_word(av[1]);
        int i = 0;

        // Allocate memory for buf and s
        char *buf = (char *)malloc(sizeof(char) * (buf_len + 1));
        char *s = (char *)malloc(sizeof(char) * (slen(av[1]) + 1));

        if (!buf || !s)
        {
            write(2, "Memory allocation error\n", 24);
            return (1); // Return an error code
        }

        buf_len = skip_space(&av[1][buf_len]);

        while (av[1][buf_len])
        {
            if (av[1][buf_len] == ' ' || (av[1][buf_len] > 8 && av[1][buf_len] < 14))
            {
                s[i] = ' '; // Use a single space between words
                while (av[1][buf_len] == ' ' || (av[1][buf_len] > 8 && av[1][buf_len] < 14))
                    buf_len++;
            }
            else
            {
                s[i] = av[1][buf_len];
                buf_len++;
            }
            i++;
        }

        s[i] = '\0';

        // Write the result to the standard output
        write(1, s, slen(s));
    }

    write(1, "\n", 1);

    return 0; // Return success code
}*/
#include <unistd.h>

int main (int ac , char **av)
{
	int i = 0;
	int j;

	if (ac >= 2)
	{
		
		while (av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t')) // search for is_space and move the position.
			i++;
		j = i; // this is the postion of starting of the word.
		while (av[1][i])
		{
			while (av[1][i] && (av[1][i] != ' ' && av[1][i] != '\t')) // find the next word.
				i++;
			while (av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t')) // find the next word.
				i++;
			while (av[1][i] && (av[1][i] != ' ' && av[1][i] != '\t') && (av[1][i -1] == ' ' || av[1][i - 1] == '\t')) // print the word till it reaches last.
			{
				while (av[1][i] && (av[1][i] != ' ' && av[1][i] != '\t'))
				{
					write (1, &av[1][i], 1);
					i++;
				}
				write (1, " ", 1);
				i++;
			}
		}
		while (av[1][j] && (av[1][j] != ' ' && av[1][j] != '\t')) // print the first word now.
		{
			write (1, &av[1][j], 1);
			j++;
		}
	}
	write (1, "\n", 1);
}
