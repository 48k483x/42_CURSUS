/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubie <yubie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:46:21 by aboudiba          #+#    #+#             */
/*   Updated: 2023/12/16 03:07:06 by yubie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line_bonus.h"

char	*get_rest(char *buffer, size_t line_size)
{
	char	*rest;
	size_t	i;

	if (!buffer || !ft_strlen(buffer))
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	rest = ft_substr(buffer, i + 1, line_size);
	free(buffer);
	return (rest);
}

char	*get_line(char *buffer)
{
	char	*line;
	size_t	i;

	if (!buffer || !ft_strlen(buffer))
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_substr(buffer, 0, i + 1);
	return (line);
}

char	*get_read(int fd, char *buffer)
{
	char	*read_buffer;
	int		read_bytes;

	read_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!read_buffer)
		return (NULL);
	while (1)
	{
		read_bytes = read(fd, read_buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(buffer), free(read_buffer), NULL);
		read_buffer[read_bytes] = '\0';
		if (read_bytes == 0)
			break ;
		if (!buffer)
			buffer = ft_strdup("");
		buffer = ft_strjoin(buffer, read_buffer);
		if (ft_strnl(buffer))
			break ;
	}
	free(read_buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > SIZE_MAX || fd > MAX_FD)
		return (NULL);
	buffer[fd] = get_read(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = get_line(buffer[fd]);
	buffer[fd] = get_rest(buffer[fd], ft_strlen(buffer[fd]));
	return (line);
}

// int main()
// {
//     int fd1 = open("text.txt", O_RDONLY);
//     int fd2 = open("text.txt", O_RDONLY);
//     int fd3 = open("text.txt", O_RDONLY);
//     int fd4 = open("text.txt", O_RDONLY);
//     while(1){
//         char *s1 = get_next_line(fd1);
//         char *s2 = get_next_line(fd2);
//         char *s3 = get_next_line(fd3);
//         char *s4 = get_next_line(fd4);
//         if (!s1 || !s2 || !s3 || !s4)
//             break ;
//         printf("%s", s1);
//         printf("%s", s2);
//         printf("%s", s3);
//         printf("%s", s4);
//         free(s1);
//         free(s2);
//         free(s3);
//         free(s4);

//     }
//     return (0);
// }
