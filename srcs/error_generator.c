/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_generator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saghighi <saghighi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:15:08 by saghighi          #+#    #+#             */
/*   Updated: 2025/03/17 17:17:24 by saghighi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	error_initiation_tx(char *msg, t_play *game)
{
	ft_putstr_fd(msg, 2);
	free_resources(game);
	exit(EXIT_FAILURE);
}

void	error_initiation_pic(char *msg, t_play *game)
{
	ft_putstr_fd(msg, 2);
	free_resources(game);
	exit(EXIT_FAILURE);
}
