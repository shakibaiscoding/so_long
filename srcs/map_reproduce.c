/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reproduce.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saghighi <saghighi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:19:06 by saghighi          #+#    #+#             */
/*   Updated: 2025/03/17 17:37:15 by saghighi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	find_player(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*y = i;
				*x = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map_collectibles(char **map)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	map_check_ber(char *filename)
{
	int	len;
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!filename)
		return (1);
	len = ft_strlen(filename);
	if (len < 5)
		return (1);
	if (ft_strncmp(filename + len - 4, ".ber", 4) != 0)
		return (1);
	while (i <= len - 4)
	{
		if (ft_strncmp(filename + i, ".ber", 4) == 0)
			count++;
		if (count > 1)
			return (1);
		i++;
	}
	return (0);
}

char	**reproduce_map(char **map)
{
	int		line;
	int		n;
	char	**copy;

	n = 0;
	line = 0;
	while (map[line])
		line++;
	copy = malloc((line + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	while (n < line)
	{
		copy[n] = ft_strdup(map[n]);
		if (!copy[n])
		{
			while (--n >= 0)
				free(copy[n]);
			free(copy);
			return (NULL);
		}
		n++;
	}
	copy[line] = NULL;
	return (copy);
}
