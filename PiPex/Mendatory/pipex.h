#ifndef PIPEX_H
#define PIPEX_H

# include <unistd.h> // dup2, pipe, close, execvp
# include <sys/types.h> // pid_t
# include <sys/wait.h> // wait
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_pipex
{
    char **cmd1;
    char **cmd2;
    int fd[2];
    pid_t pid;
    int fd1;
    int fd2;
    char *path;
    char *spath;
}   t_data;

/* split Functions */
int     count_strings(char const *s, char c);
char    *malloc_strings(const char *s, char c);
char    **ft_split(char const *s, char c);

/* utils Function and if you need any explaination you can read it file itself */
void    exiti(char *s);
char    *str_concat(char *s1, char *s2);
int     ft_strlen(char *s);

#endif // PIPEX_H
