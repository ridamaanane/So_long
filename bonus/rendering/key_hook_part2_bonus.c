/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_part2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaanane <rmaanane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:27:34 by rmaanane          #+#    #+#             */
/*   Updated: 2025/03/13 04:38:07 by rmaanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	key_hook(int keycode, t_game *game)
{
	int	new_position_x;
	int	new_position_y;

	update_player_direction(keycode, game, &new_position_y, &new_position_x);
	handle_game_over(keycode, game, new_position_y, new_position_x);
	if (game->map[new_position_y][new_position_x] == 'C')
		handle_collectible(game, new_position_y, new_position_x);
	if (game->map[new_position_y][new_position_x] == 'E')
		handle_exit_door(game, new_position_y, new_position_x);
	handle_player_movement(game, new_position_y, new_position_x);
	display_map(game);
	return (0);
}

void	load_images_bonus(t_game *game, int width, int height)
{
	game->enemy_imgs[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/enemy1.xpm", &width, &height);
	game->enemy_imgs[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/enemy2.xpm", &width, &height);
	game->enemy_imgs[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/enemy3.xpm", &width, &height);
	game->enemy_imgs[3] = mlx_xpm_file_to_image(game->mlx,
			"textures/enemy4.xpm", &width, &height);
	game->enemy_imgs[4] = mlx_xpm_file_to_image(game->mlx,
			"textures/enemy5.xpm", &width, &height);
	game->enemy_imgs[5] = mlx_xpm_file_to_image(game->mlx,
			"textures/enemy6.xpm", &width, &height);
	game->enemy_current_img = 0;
}

void	load_more_images_bonus(t_game *game, int width, int height)
{
	game->counter_img = mlx_xpm_file_to_image(game->mlx,
			"textures/counter.xpm", &width, &height);
	game->background_yellow = mlx_xpm_file_to_image(game->mlx,
			"textures/background_yellow.xpm", &width, &height);
	game->numbers[0] = mlx_xpm_file_to_image(game->mlx, "textures/0.xpm",
			&width, &height);
	game->numbers[1] = mlx_xpm_file_to_image(game->mlx, "textures/1.xpm",
			&width, &height);
	game->numbers[2] = mlx_xpm_file_to_image(game->mlx, "textures/2.xpm",
			&width, &height);
	game->numbers[3] = mlx_xpm_file_to_image(game->mlx, "textures/3.xpm",
			&width, &height);
	game->numbers[4] = mlx_xpm_file_to_image(game->mlx, "textures/4.xpm",
			&width, &height);
	game->numbers[5] = mlx_xpm_file_to_image(game->mlx, "textures/5.xpm",
			&width, &height);
	game->numbers[6] = mlx_xpm_file_to_image(game->mlx, "textures/6.xpm",
			&width, &height);
	game->numbers[8] = mlx_xpm_file_to_image(game->mlx, "textures/8.xpm",
			&width, &height);
	game->numbers[7] = mlx_xpm_file_to_image(game->mlx, "textures/7.xpm",
			&width, &height);
	game->numbers[9] = mlx_xpm_file_to_image(game->mlx, "textures/9.xpm",
			&width, &height);
}

int	destroy_callback(t_game *game)
{
	return (free_leaks_mlx(game, "X detected\n"));
}
