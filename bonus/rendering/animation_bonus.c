/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaanane <rmaanane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 00:59:33 by rmaanane          #+#    #+#             */
/*   Updated: 2025/03/13 23:38:32 by rmaanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	rander_steps_counter(t_game *game)
{
	int	steps;

	steps = game->key_count;
	mlx_put_image_to_window(game->mlx, game->win, game->numbers[(steps / 10000)
		% 10], 250, 15);
	mlx_put_image_to_window(game->mlx, game->win, game->numbers[(steps / 1000)
		% 10], 305, 15);
	mlx_put_image_to_window(game->mlx, game->win, game->numbers[(steps / 100)
		% 10], 357, 15);
	mlx_put_image_to_window(game->mlx, game->win, game->numbers[(steps / 10)
		% 10], 413, 15);
	mlx_put_image_to_window(game->mlx, game->win, game->numbers[steps % 10],
		469, 15);
}

int	animate_enemy(t_game *game)
{
	static unsigned int	frame_counter;

	int (x), (y);
	frame_counter++;
	if (frame_counter % 12000 != 0)
		return (0);
	game->enemy_current_img++;
	if (game->enemy_current_img >= 6)
		game->enemy_current_img = 0;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'K')
				mlx_put_image_to_window(game->mlx, game->win,
					game->enemy_imgs[game->enemy_current_img], x * TILE_SIZE, y
					* TILE_SIZE + 100);
			x++;
		}
		y++;
	}
	return (0);
}

void	background_yellow(t_game *game)
{
	int	dx;
	int	map_width_in_pixels;

	mlx_put_image_to_window(game->mlx, game->win, game->counter_img, 0, 0);
	map_width_in_pixels = game->map_width * TILE_SIZE;
	dx = 600;
	while (dx < map_width_in_pixels)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->background_yellow,
			dx, 0);
		dx += 600;
	}
}
