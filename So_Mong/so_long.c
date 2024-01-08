/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 08:12:16 by achahrou          #+#    #+#             */
/*   Updated: 2024/01/08 08:12:26 by achahrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int error_mssg(char *s, int ERR_TYPE)
{
	errno = ERR_TYPE;
	perror(s);
	return (1);
}

int check(int c)
{
	if (c == '1' || c == 'E' || c == 'C' || c == 'X')
		return (1);
	else
		return (0);
}

int main(int ac, char **av)
{
	t_data data;
	data.map = NULL;
	char *line;
	if (ac != 2 /*|| !ft_strnstr(av[1], ".ber", ft_strlen(av[1])*/)
		return (error_mssg("No Map Loaded, Try Again", EINVAL));
	int fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (error_mssg("Error: Failed to open map\n", EPERM));
	while ((line = get_next_line(fd)))
		data.map = add_to_map(data.map, line);
	if (!data.map)
		return (error_mssg("Error: Failed to read map\n", EPERM));
	if (!validate_map(&data) || !check_map_row_len(&data))
		return (error_mssg(
			 "Error: Invalid map Or The The Rows Len Are Not The Same.\n", EPERM));
	if (!window_init(&data))
		error_mssg("Error: Failed to initialize window\n", EPERM);
	free(data.map);
	close(fd);
	return (0);
}
