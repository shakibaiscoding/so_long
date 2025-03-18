/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saghighi <saghighi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:36:29 by saghighi          #+#    #+#             */
/*   Updated: 2025/03/17 17:15:39 by saghighi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	free_images(t_play *game)
{
	if (game->wall_pic)
		mlx_delete_image(game->mlx, game->wall_pic);
	if (game->floor_pic)
		mlx_delete_image(game->mlx, game->floor_pic);
	if (game->player_pic)
		mlx_delete_image(game->mlx, game->player_pic);
	if (game->collectible_pic)
		mlx_delete_image(game->mlx, game->collectible_pic);
	if (game->exit_pic)
		mlx_delete_image(game->mlx, game->exit_pic);
}

static void	free_textures(t_play *game)
{
	if (game->wall_tx)
		mlx_delete_texture(game->wall_tx);
	if (game->floor_tx)
		mlx_delete_texture(game->floor_tx);
	if (game->player_tx)
		mlx_delete_texture(game->player_tx);
	if (game->collectible_tx)
		mlx_delete_texture(game->collectible_tx);
	if (game->exit_tx)
		mlx_delete_texture(game->exit_tx);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	free_resources(t_play *game)
{
	if (!game)
		return ;
	free_images(game);
	free_textures(game);
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game->map)
		free_map(game->map);
}
