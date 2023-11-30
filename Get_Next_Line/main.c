/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <achahrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 00:34:37 by achahrou          #+#    #+#             */
/*   Updated: 2023/11/30 00:50:12 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

int
main(void)
{
        /*int     fd = open("abdu.txt", O_RDWR | O_CREAT | O_APPEND);
	printf("This the fd :    %d\n", fd);
	dup2(fd, 1);
        write(1, "Hello Abdurrahman\n", 18);
        write(fd,"Hello Abdurrahman\n", 18);*/
	char	buf[256];
	int	readed_chars;
	int	fd = open("abdu.txt", O_RDONLY | O_CREAT);
	while ((readed_chars = read (fd, buf, 18)))
	{
		buf[readed_chars] = '\0';
		printf("buf -> %s\n", buf);
	}
}
