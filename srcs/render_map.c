/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saghighi <saghighi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:12:33 by saghighi          #+#    #+#             */
/*   Updated: 2025/03/17 17:39:47 by saghighi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	rendering_map_exit(t_play *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->exit_pic,
					x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

void	render_map(void *param)
{
	t_play	*game;

	game = (t_play *)param;
	if (!game->wall_pic || !game->floor_pic || !game->player_pic)
	{
		ft_putstr_fd("Error: Textures not loaded\n", 2);
		exit(1);
	}
	rendering_map_floor(game);
	rendering_map_wall(game);
	rendering_map_player(game);
	rendering_map_collectible(game);
	rendering_map_exit(game);
}
