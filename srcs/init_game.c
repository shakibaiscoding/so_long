/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saghighi <saghighi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:49:40 by saghighi          #+#    #+#             */
/*   Updated: 2025/03/18 16:38:50 by saghighi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_game_tx(t_play *game)
{
	game->wall_tx = mlx_load_png("assets/wall.png");
	game->floor_tx = mlx_load_png("assets/floor.png");
	game->player_tx = mlx_load_png("assets/player.png");
	game->collectible_tx = mlx_load_png("assets/collectible.png");
	game->exit_tx = mlx_load_png("assets/exit.png");
	if (!game->wall_tx || !game->floor_tx || !game->player_tx
		||!game->collectible_tx || !game->exit_tx)
		error_initiation_tx("Error: Texture loading failed\n", game);
}

void	init_game_pics(t_play *game)
{
	int	ret;

	game->wall_pic = mlx_texture_to_image(game->mlx, game->wall_tx);
	game->floor_pic = mlx_texture_to_image(game->mlx, game->floor_tx);
	game->player_pic = mlx_texture_to_image(game->mlx, game->player_tx);
	game->collectible_pic = mlx_texture_to_image
		(game->mlx, game->collectible_tx);
	game->exit_pic = mlx_texture_to_image(game->mlx, game->exit_tx);
	if (!game->wall_pic || !game->floor_pic || !game->player_pic
		||!game->collectible_pic || !game->exit_pic)
		error_initiation_pic("Error: Image creation failed\n", game);
	ret = mlx_image_to_window(game->mlx, game->player_pic,
			game->x_position * TILE_SIZE, game->y_position * TILE_SIZE);
	if (ret < 0)
		error_initiation_pic("Error: Could not place player image\n", game);
}

void	start_position(t_play *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'P')
			{
				game->x_position = x;
				game->y_position = y;
				return ;
			}
			x++;
		}
		y++;
	}
	error_initiation_pic("Error: Player position not found in map\n", game);
}
