#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    char *env_path = getenv("PATH");
    printf("%s\n", env_path);
}
