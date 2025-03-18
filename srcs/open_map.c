/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saghighi <saghighi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:28:00 by saghighi          #+#    #+#             */
/*   Updated: 2025/03/17 17:37:06 by saghighi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	open_map_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_putstr_fd("Error: couldn't open file\n", 2);
	return (fd);
}

static void	update_map_dimensions(t_play *game, int width, int *first_line)
{
	game->map_height++;
	if (*first_line)
	{
		game->map_width = width;
		*first_line = 0;
	}
}

static void	read_map(int fd, t_play *game)
{
	char	buffer;
	int		width;
	int		first_line;

	width = 0;
	first_line = 1;
	game->map_width = 0;
	game->map_height = 0;
	while (read(fd, &buffer, 1) > 0)
	{
		if (buffer == '\n')
		{
			update_map_dimensions(game, width, &first_line);
			width = 0;
		}
		else
			width++;
	}
	if (width > 0)
		game->map_height++;
}

void	get_map_size(char *filename, t_play *game)
{
	int	fd;

	fd = open_map_file(filename);
	if (fd < 0)
		return ;
	read_map(fd, game);
	close(fd);
	if (game->map_width == 0 || game->map_height == 0)
		ft_putstr_fd("Error: Invalid map\n", 2);
}
