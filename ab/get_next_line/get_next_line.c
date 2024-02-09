/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubie <yubie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:46:21 by aboudiba          #+#    #+#             */
/*   Updated: 2023/12/17 15:16:10 by yubie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*get_rest(char *buffer, size_t line_size)
{
	char	*rest;
	size_t	i;

	if (!buffer || !ft_strlen_gnl(buffer))
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	rest = ft_substr_gnl(buffer, i + 1, line_size);
	free(buffer);
	return (rest);
}

char	*get_line(char *buffer)
{
	char	*line;
	size_t	i;

	if (!buffer || !ft_strlen_gnl(buffer))
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_substr_gnl(buffer, 0, i + 1);
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
			buffer = ft_strdup_gnl("");
		buffer = ft_strjoin_gnl(buffer, read_buffer);
		if (ft_strnl_gnl(buffer))
			break ;
	}
	free(read_buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > SIZE_MAX || fd > MAX_FD)
		return (NULL);
	buffer = get_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	buffer = get_rest(buffer, ft_strlen_gnl(buffer));
	return (line);
}

// int main()
// {
//     // int fd = open("text.txt", O_RDONLY);
//     char *s = get_next_line(-1);
//     printf("%s", s);
//     free(s);
//     return (0);
// }
