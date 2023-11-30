/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:27:00 by achahrou          #+#    #+#             */
/*   Updated: 2023/11/30 14:58:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char		*line;
	int		readed;
	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	readed = 1;
	line = NULL;
	// 1. read from fd and add to linked list
	read_and_list(fd, &list, &readed);
	if (list == NULL)
		return (NULL);
	// 2. extract from list to line
	extract_line(list, &line);
	// 3. clean up list
	return (NULL);
}
/* use read() to add characters to the list */

void	read_and_list(int fd, t_list **list, int *readed_ptr)
{
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return ;
	while (!found_newline(*list) && *readed_ptr != 0)
	{
		*readed_ptr = (int)read(fd, buf, BUFFER_SIZE);
	 	if ((*list == NULL && *readed_ptr == 0) || *readed_ptr == -1)
		{
			free(buf);
			return ;
		}
		buf[*readed_ptr] = '\0';
		add_to_list(buf, *readed_ptr);
		free(buf);
	}
}
/* Add the content of our buffer to the end of our list */
void	add_to_list(t_list **list, char *buf, int readed)
{
	int	i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;	
	new_node->next = NULL;
	new_node->content =	malloc(sizeof(char) * (readed+ 1));
	if (new_node->content == NULL)	
		return ;
	i = 0;
	while (buf[i] && i < readed)
	{
		new_node->content[i] = buf[i];
		i++;
	}
	new_node->current[i] = '\0';
	if (*list == NULL)
	{
		*list = new_node;
		return ;
	}
	last = ft_lst_get_last(*list);
	last->next = NULL;
}
/* Extracts our chars from the our list and stores them in our line */
/* And of course stopping after the first \n encounters */

void	extract_chars(t_list *list, char **line)
{
	int i;
	int	j;

	if (last == NULL)
		return ;
	generate_line(line, list);
	if (*line == NULL)
        return ;
}