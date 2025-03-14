/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaanane <rmaanane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:28:03 by rmaanane          #+#    #+#             */
/*   Updated: 2025/03/13 21:12:48 by rmaanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	init_game(t_game *game)
{
	game->key_count = 0;
	game->collected = 0;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map_width * TILE_SIZE,
			game->map_height * TILE_SIZE + 100, "Sheep Protector");
}

void	check_images(t_game *game)
{
	if (!game->wall_img || !game->collectible_img || !game->floor_img
		|| !game->player_imgs[0] || !game->player_imgs[1]
		|| !game->player_imgs[2] || !game->player_imgs[1]
		|| !game->player_imgs[2] || !game->player_imgs[3] || !game->door_imgs[0]
		|| !game->door_imgs[1] || !game->enemy_imgs[0] || !game->enemy_imgs[1]
		|| !game->enemy_imgs[2] || !game->enemy_imgs[3] || !game->enemy_imgs[4]
		|| !game->enemy_imgs[5] || !game->player_imgs[3] || !game->counter_img
		|| !game->background_yellow || !game->counter_img
		|| !game->collectible_img || !game->numbers[0] || !game->numbers[1]
		|| !game->numbers[2] || !game->numbers[3] || !game->numbers[4]
		|| !game->numbers[5] || !game->numbers[6] || !game->numbers[7]
		|| !game->numbers[8] || !game->numbers[9])
	{
		write(2, "Error\nin loading images\n", 26);
		exit(1);
	}
}

void	load_images(t_game *game)
{
	int (width), (height);
	game->floor_img = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &width, &height);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&width, &height);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &width, &height);
	game->player_imgs[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/player_right.xpm", &width, &height);
	game->player_imgs[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/player_left.xpm", &width, &height);
	game->player_imgs[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/player_up.xpm", &width, &height);
	game->player_imgs[3] = mlx_xpm_file_to_image(game->mlx,
			"textures/player_down.xpm", &width, &height);
	game->player_current_img = 0;
	game->door_imgs[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/close_door.xpm", &width, &height);
	game->door_imgs[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/open_door.xpm", &width, &height);
	game->door_current_img = 0;
	load_images_bonus(game, width, height);
	load_more_images_bonus(game, width, height);
}

void	setup_map(t_game *game, char *file_path)
{
	int	x;
	int	y;

	if (!(check_file_name(file_path)))
		exit(1);
	game->map = read_map(game, file_path);
	game->total_collectibles = 0;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			set_game_tiles(game, x, y);
			x++;
		}
		y++;
	}
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (1);
	setup_map(&game, av[1]);
	init_game(&game);
	load_images(&game);
	check_images(&game);
	mlx_hook(game.win, 02, (1L << 0), key_hook, &game);
	mlx_hook(game.win, 17, 0, destroy_callback, &game);
	mlx_loop_hook(game.mlx, animate_enemy, &game);
	background_yellow(&game);
	display_map(&game);
	mlx_loop(game.mlx);
	return (0);
}
