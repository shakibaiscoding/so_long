/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_assets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saghighi <saghighi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:23:10 by saghighi          #+#    #+#             */
/*   Updated: 2025/03/18 12:15:30 by saghighi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	rendering_map_wall(t_play *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game -> map_width)
		{
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->wall_pic,
					x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

void	rendering_map_floor(t_play *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game -> map_width)
		{
			if (game->map[y][x] != '1')
				mlx_image_to_window(game->mlx, game->floor_pic,
					x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

void	rendering_map_player(t_play *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game -> map_width)
		{
			if (game->map[y][x] == 'P')
				mlx_image_to_window(game->mlx, game->player_pic,
					x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

void	rendering_map_collectible(t_play *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game -> map_width)
		{
			if (game->map[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->collectible_pic,
					x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}
