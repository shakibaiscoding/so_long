/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saghighi <saghighi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:02:20 by saghighi          #+#    #+#             */
/*   Updated: 2025/03/18 12:52:32 by saghighi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{
	t_play	game;

	if (ac != 2)
		return (ft_putstr_fd("Usage is: ./so_long map.ber\n", 2), 1);
	if (map_check_ber(av[1]))
		return (ft_putstr_fd("Error: Invalid file extension\n", 2), 1);
	init_game(&game, av[1]);
	mlx_key_hook(game.mlx, handle_input, &game);
	mlx_loop(game.mlx);
	free_resources(&game);
	return (0);
}
