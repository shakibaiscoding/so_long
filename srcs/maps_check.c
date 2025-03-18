/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saghighi <saghighi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:22:13 by saghighi          #+#    #+#             */
/*   Updated: 2025/03/17 17:35:00 by saghighi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	excistance_map(int fd)
{
	if (fd == -1)
		return (ft_putendl_fd("Error : Map file not found!", 2), 1);
	return (0);
}

int	map_rectangle_check(char **map)
{
	int		i;
	size_t	length;

	i = 0;
	length = ft_strlen(map[i]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != length)
			return (0);
		i++;
	}
	return (1);
}

int	input_map_check(char **map)
{
	if (map[0] == NULL)
		return (ft_putendl_fd("Error: Map file is empty!", 2), 1);
	return (0);
}

int	enclosure_map_check(char **map)
{
	int	i;
	int	j;
	int	width;
	int	height;

	height = 0;
	width = ft_strlen(map[0]);
	while (map[height])
		height++;
	j = 0;
	while (j < width)
	{
		if (map[0][j] != '1' || map[height - 1][j] != '1')
			return (0);
		j++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
