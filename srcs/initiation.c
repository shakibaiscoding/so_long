/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saghighi <saghighi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:33:58 by saghighi          #+#    #+#             */
/*   Updated: 2025/03/18 16:49:35 by saghighi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	check_window_size(t_play *game)
{
	int	window_width;
	int	window_height;

	window_width = game->map_width * TILE_SIZE;
	window_height = game->map_height * TILE_SIZE;
	if (window_width > MAX_SCREEN_WIDTH || window_height > MAX_SCREEN_HEIGHT)
	{
		ft_putstr_fd("Error: Map size exceeds screen dimensions!\n", 2);
		return (1);
	}
	return (0);
}

static void	check_map_validity(t_play *game, char *map_file)
{
	get_map_size(map_file, game);
	if (exit_map_check(game->map) || player_map_check(game->map)
		|| !check_collectibles(game->map) || check_character(game->map)
		|| !enclosure_map_check(game->map) || !map_rectangle_check(game->map)
		||check_accessibility(game->map) || check_window_size(game))
	{
		error_initiation_tx("Error: Invalid map\n", game);
	}
}

static void	initialize_game_variables(t_play *game)
{
	game->moves = 0;
	game->collected_ones = 0;
	game->collectibles = check_map_collectibles(game->map);
	ft_putstr_fd("Total collectibles in this map: ", 1);
	ft_putnbr_fd(game->collectibles, 1);
	write(1, "\n", 1);
}

void	init_game(t_play *game, char *map_file)
{
	ft_memset(game, 0, sizeof(t_play));
	game->map = load_map_from_file(map_file);
	if (!game->map)
		error_initiation_tx("Error: Map loading failed\n", game);
	check_map_validity(game, map_file);
	game->mlx = mlx_init(game->map_width * TILE_SIZE,
			game->map_height * TILE_SIZE, "so_long", true);
	if (!game->mlx)
		error_initiation_tx("Error: MLX Initialization failed\n", game);
	start_position(game);
	initialize_game_variables(game);
	init_game_tx(game);
	init_game_pics(game);
	render_map(game);
}
