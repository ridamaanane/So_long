/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaanane <rmaanane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:12:24 by rmaanane          #+#    #+#             */
/*   Updated: 2025/03/15 00:31:39 by rmaanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 64
# define ESC_KEY 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define W 119
# define A 97
# define S 115
# define D 100

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*wall_img;
	void	*floor_img;
	void	*collectible_img;
	void	*player_imgs[4];
	int		player_current_img;
	void	*door_imgs[2];
	int		door_current_img;
	int		player_x;
	int		player_y;
	int		collected;
	int		total_collectibles;
	int		key_count;
	int		map_height;
	int		map_width;
	int		pos_exit_x;
	int		pos_exit_y;
}			t_game;

// display
void		display_map(t_game *game);
void		set_game_tiles(t_game *game, int x, int y);

// key_hook_part1.c
void		handle_player_movement(t_game *game, int new_position_y,
				int new_position_x);
int			handle_game_over(int keycode, t_game *game);
void		handle_collectible(t_game *game, int new_position_y,
				int new_position_x);
void		handle_exit_door(t_game *game, int new_position_y,
				int new_position_x);
void		update_player_direction(int keycode, t_game *game,
				int *new_position_y, int *new_position_x);

////key_hook_part2
int			key_hook(int keycode, t_game *game);
int			destroy_callback(t_game *game);

// read_map
char		**read_map(t_game *game, char *file_path);
int			count_lines(char *file_path);
size_t		no_line_strlen(char *str);

// parsing/check_ber
int			check_file_name(char *file_path);

// parsing/check_characters
int			is_valid_char(char c);
int			validate_map_structure(t_game *game, int cols, int rows);
int			check_required_elements(t_game *game, int width, int height);

// parsing/check_rectangularity
int			check_rectangular(t_game *game, int width, int height);

// parsing/check_walls
int			check_walls(t_game *game, int width, int height);

// parsing/check_path
void		check_path(t_game *game);

// free_leaks
int			free_leaks_mlx(t_game *game, char *msg);
void		free_map(char **map);

#endif
