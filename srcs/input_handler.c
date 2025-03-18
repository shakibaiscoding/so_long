/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saghighi <saghighi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:47:20 by saghighi          #+#    #+#             */
/*   Updated: 2025/03/18 13:05:23 by saghighi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	update_display(t_play *game)
{
	mlx_delete_image(game->mlx, game->player_pic);
	game->player_pic = mlx_texture_to_image(game->mlx, game->player_tx);
	if (!game->player_pic)
		error_initiation_pic("Error recreating player image\n", game);
	if (mlx_image_to_window(game->mlx, game->player_pic,
			game->x_position * TILE_SIZE,
			game->y_position * TILE_SIZE) < 0)
		error_initiation_pic("Error placing player image\n", game);
}

static int	is_valid_move(t_play *game, int new_x, int new_y)
{
	if (new_x < 0 || new_y < 0
		|| new_x >= game->map_width || new_y >= game->map_height)
		return (0);
	if (game->map[new_y][new_x] == '1')
	{
		ft_putstr_fd("!You hit the wall!\n", 2);
		return (0);
	}
	return (1);
}

static void	handle_collectible(t_play *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'C')
	{
		game->collected_ones++;
		game->map[new_y][new_x] = '0';
		render_map(game);
		ft_putstr_fd("Collectible picked up! [", 1);
		ft_putnbr_fd(game->collected_ones, 1);
		ft_putstr_fd("/", 1);
		ft_putnbr_fd(game->collectibles, 1);
		ft_putstr_fd(" collected]\n", 1);
	}
}

void	move(t_play *game, int delta_x, int delta_y)
{
	int	new_x;
	int	new_y;

	new_x = game->x_position + delta_x;
	new_y = game->y_position + delta_y;
	if (!is_valid_move(game, new_x, new_y))
		return ;
	if (game->map[new_y][new_x] == 'E'
		&& game->collected_ones == game->collectibles)
	{
		ft_putstr_fd("Game Finished!Good job!!\n", 1);
		mlx_close_window(game->mlx);
		return ;
	}
	handle_collectible(game, new_x, new_y);
	game->x_position = new_x;
	game->y_position = new_y;
	update_display(game);
	game->moves++;
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(game->moves, 1);
	write(1, "\n", 1);
}

void	handle_input(mlx_key_data_t keydata, void *param)
{
	t_play	*game;

	game = (t_play *)param;
	if (keydata.action != MLX_PRESS && keydata.action != MLX_REPEAT)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
	else if (keydata.key == MLX_KEY_W)
		move(game, 0, -1);
	else if (keydata.key == MLX_KEY_S)
		move(game, 0, 1);
	else if (keydata.key == MLX_KEY_A)
		move(game, -1, 0);
	else if (keydata.key == MLX_KEY_D)
		move(game, 1, 0);
}
