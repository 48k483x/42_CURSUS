/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:57:09 by achahrou          #+#    #+#             */
/*   Updated: 2023/11/30 14:58:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*Look for an new line line in the given linked list*/
int found_newline(t_list *list)
{
    int i;
    t_list *current;

    if (list == NULL)
        return (0);
    current = ft_lst_get_last(list);
    i = 0;
    while (current->content[i])
    {
        if (current->content[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}
/* Return an pointer to the last node in our list */
t_list  ft_lst_get_last(t_list *list)
{
    t_list  current;

    current = list;
    while (current && current->next)
        current = current->next;
    return (current);
}
/* Calculate the chars in the the current line Including the trailing \n if there is one
    and allocate mem accordingly*/
void    generate_line(char **line, t_list *list)
{
    int i;
    int len;

    len = 0;
    while (list)
    {
        i = 0;
        while (list->content[i])
        {
            if (list->content[i] == '\n')
            {
                len++;
                break;
            }
            len++;
            i++;
        }
        list = list->next 
    }
    *line = malloc(sizeof(char) * (len + 1));
}
