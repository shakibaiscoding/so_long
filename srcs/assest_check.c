/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assest_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saghighi <saghighi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:31:40 by saghighi          #+#    #+#             */
/*   Updated: 2025/03/17 17:36:50 by saghighi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	exit_map_check(char **map)
{
	int	i;
	int	j;
	int	e;

	i = 0;
	e = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				e++;
			j++;
		}
		i++;
	}
	if (e != 1)
		return (ft_putstr_fd("Error:More than one exit\n", 2), 1);
	return (0);
}

int	player_map_check(char **map)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	p = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				p++;
			j++;
		}
		i++;
	}
	if (p != 1)
		return (ft_putstr_fd("Error: More than one player\n", 2), 1);
	return (0);
}

int	check_collectibles(char **map)
{
	int	i;
	int	j;
	int	collectibles;

	i = 0;
	collectibles = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				collectibles++;
			j++;
		}
		i++;
	}
	if (collectibles >= 1)
		return (1);
	else
		return (0);
}

int	check_character(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'C' && map[i][j] != 'P' && map[i][j] != 'E' &&
				map[i][j] != '1' && map[i][j] != '0')
			{
				ft_putendl_fd("Invalid character", 2);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
