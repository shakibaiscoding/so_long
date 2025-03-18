/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saghighi <saghighi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:48:46 by saghighi          #+#    #+#             */
/*   Updated: 2025/03/18 12:41:58 by saghighi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define TILE_SIZE 64
# define WIDTH 1200
# define HEIGHT 1000
# define MAX_LINE_LENGTH 1024
# define MAX_BUFFER_SIZE 1024

typedef struct s_play
{
	mlx_t			*mlx;
	mlx_image_t		*wall_pic;
	mlx_image_t		*floor_pic;
	mlx_image_t		*player_pic;
	mlx_image_t		*exit_pic;
	mlx_image_t		*collectible_pic;
	mlx_texture_t	*wall_tx;
	mlx_texture_t	*floor_tx;
	mlx_texture_t	*player_tx;
	mlx_texture_t	*exit_tx;
	mlx_texture_t	*collectible_tx;
	char			**map;
	int				map_width;
	int				map_height;
	int				x_position;
	int				y_position;
	int				collectibles;
	int				collected_ones;
	int				moves;
}	t_play;

typedef struct s_flood
{
	int	c_count;
	int	found_exit;
}	t_flood;

void	render_map(void *param);
void	free_resources(t_play *game);
void	error_initiation_tx(char *msg, t_play *game);
void	error_initiation_pic(char *msg, t_play *game);
void	get_map_size(char *filename, t_play *game);
int		check_character(char **map);
int		check_collectibles(char **map);
int		player_map_check(char **map);
int		exit_map_check(char **map);
int		enclosure_map_check(char **map);
int		input_map_check(char **map);
int		map_rectangle_check(char **map);
int		excistance_map(int fd);
void	init_game(t_play *game, char *map_file);
char	**load_map_from_file(char *filename);
int		map_check_ber(char *filename);
void	handle_input(mlx_key_data_t keydata, void *param);
void	update_display(t_play *game);
int		find_player(char **map, int *x, int *y);
int		check_map_collectibles(char **map);
void	start_position(t_play *game);
void	free_map(char **map);
int		check_accessibility(char **map);
char	**reproduce_map(char **map);
void	rendering_map_collectible(t_play *game);
void	rendering_map_player(t_play *game);
void	rendering_map_floor(t_play *game);
void	rendering_map_wall(t_play *game);
void	init_game_tx(t_play *game);
void	init_game_pics(t_play *game);
int		get_line_length(char *content, int index);
char	**allocate_map(int height);
char	*read_file_content(int fd);
int		count_lines(char *content);
#endif
