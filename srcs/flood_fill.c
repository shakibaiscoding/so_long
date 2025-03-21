/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saghighi <saghighi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:37:33 by saghighi          #+#    #+#             */
/*   Updated: 2025/03/18 16:18:39 by saghighi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	flood_fill(char **map, int x, int y, t_flood *flood)
{
	if (x < 0 || y < 0 || !map[y] || !map[y][x] || map[y][x] == '1'
	|| map[y][x] == 'V')
		return ;
	if (map[y][x] == 'C')
		flood->c_count++;
	if (map[y][x] == 'E')
		flood->found_exit = 1;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, flood);
	flood_fill(map, x - 1, y, flood);
	flood_fill(map, x, y + 1, flood);
	flood_fill(map, x, y - 1, flood);
}

int	check_accessibility(char **map)
{
	int		x;
	int		y;
	char	**copy_map;
	int		result;
	t_flood	flood;

	flood = (t_flood){0};
	copy_map = reproduce_map(map);
	if (!copy_map)
		return (ft_putstr_fd("Error: Memory allocation failed\n", 2), 1);
	if (!find_player(map, &x, &y))
		return (free_map(copy_map), ft_putstr_fd("Error: no player\n", 2), 1);
	flood_fill(copy_map, x, y, &flood);
	result = (flood.c_count == check_map_collectibles(map) && flood.found_exit);
	free_map(copy_map);
	if (!result)
		ft_putstr_fd("Invalid map: There is no collectible or exit\n", 2);
	return (!result);
}
