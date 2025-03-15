/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaanane <rmaanane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:16:26 by rmaanane          #+#    #+#             */
/*   Updated: 2025/03/15 00:22:34 by rmaanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img_to_win(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->player_imgs[game->player_current_img], x * TILE_SIZE, y
			* TILE_SIZE);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->collectible_img, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] != 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->floor_img, x
			* TILE_SIZE, y * TILE_SIZE);
}

void	display_map(t_game *game)
{
	int	x;
	int	y;

	if (game->map[game->pos_exit_y][game->pos_exit_x] != 'P')
		game->map[game->pos_exit_y][game->pos_exit_x] = 'E';
	mlx_put_image_to_window(game->mlx, game->win,
		game->door_imgs[game->door_current_img], game->pos_exit_x * TILE_SIZE,
		game->pos_exit_y * TILE_SIZE);
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			put_img_to_win(game, x, y);
			x++;
		}
		y++;
	}
}

void	set_game_tiles(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
		game->total_collectibles++;
	if (game->map[y][x] == 'P')
	{
		game->player_x = x;
		game->player_y = y;
	}
	if (game->map[y][x] == 'E')
	{
		game->pos_exit_x = x;
		game->pos_exit_y = y;
	}
}
