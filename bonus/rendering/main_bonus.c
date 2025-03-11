/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaanane <rmaanane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:28:03 by rmaanane          #+#    #+#             */
/*   Updated: 2025/03/11 03:26:19 by rmaanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_game(t_game *game)
{
	game->key_count = 0;
	game->collected = 0;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map_width * TILE_SIZE,
			game->map_height * TILE_SIZE, "Sheep Protector");
}

void	check_images(t_game *game)
{
	if (!game->wall_img || !game->collectible_img
		|| !game->floor_img || !game->player_imgs[0] ||  !game->player_imgs[1] || !game->player_imgs[2] 
		|| !game->player_imgs[1] || !game->player_imgs[2] || !game->player_imgs[3] 
		|| !game->door_imgs[0] || !game->door_imgs[1] 
		||!game->enemy_imgs[0] || !game->enemy_imgs[1] || !game->enemy_imgs[2] 
		|| !game->enemy_imgs[3] ||!game->enemy_imgs[4] || !game->enemy_imgs[5]
		|| !game->player_imgs[3] || !game->counter_img || !game->background_yellow || !game->counter_img
		|| !game-> collectible_img
		|| !game->numbers[0] || !game->numbers[1] || !game->numbers[2] || !game->numbers[3] || !game->numbers[4]
		|| !game->numbers[5] || !game->numbers[6] || !game->numbers[7] || !game->numbers[8] || !game->numbers[9]
	)
	{
		write(2, "Error:\nin loading images\n", 26);
	
	}
}

void	load_images(t_game *game)
{
	int	width;
	int	height;

	game->floor_img = mlx_xpm_file_to_image(game->mlx, "../../imgs/floor.xpm", &width, &height);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "../../imgs/wall.xpm", &width, &height);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx, "../../imgs/collectible.xpm", &width, &height);
	game->player_imgs[0] = mlx_xpm_file_to_image(game->mlx, "../../imgs/player_right.xpm", &width, &height);
	game->player_imgs[1] = mlx_xpm_file_to_image(game->mlx, "../../imgs/player_left.xpm", &width, &height);
	game->player_imgs[2] = mlx_xpm_file_to_image(game->mlx, "../../imgs/player_up.xpm", &width, &height);
	game->player_imgs[3] = mlx_xpm_file_to_image(game->mlx, "../../imgs/player_down.xpm", &width, &height);
	game->player_current_img = 0;
	game->door_imgs[0] = mlx_xpm_file_to_image(game->mlx, "../../imgs/close_door.xpm", &width, &height);
	game->door_imgs[1] = mlx_xpm_file_to_image(game->mlx, "../../imgs/open_door.xpm", &width, &height);
	game->door_current_img = 0;
	game->enemy_imgs[0] = mlx_xpm_file_to_image(game->mlx, "../../imgs/enemy1.xpm", &width, &height);
	game->enemy_imgs[1] = mlx_xpm_file_to_image(game->mlx, "../../imgs/enemy2.xpm", &width, &height);
	game->enemy_imgs[2] = mlx_xpm_file_to_image(game->mlx, "../../imgs/enemy3.xpm", &width, &height);
	game->enemy_imgs[3] = mlx_xpm_file_to_image(game->mlx, "../../imgs/enemy4.xpm", &width, &height);
	game->enemy_imgs[4] = mlx_xpm_file_to_image(game->mlx, "../../imgs/enemy5.xpm", &width, &height);
	game->enemy_imgs[5] = mlx_xpm_file_to_image(game->mlx, "../../imgs/enemy6.xpm", &width, &height);
	game->enemy_current_img = 0;
	
	game->counter_img = mlx_xpm_file_to_image(game->mlx, "../../imgs/counter.xpm", &width, &height);
	
	game->background_yellow = mlx_xpm_file_to_image(game->mlx, "../../imgs/background_yellow.xpm", &width, &height);

	game->numbers[0] = mlx_xpm_file_to_image(game->mlx , "../../imgs/0.xpm", &width, &height);
	game->numbers[1] = mlx_xpm_file_to_image(game->mlx , "../../imgs/1.xpm", &width, &height);
	game->numbers[2] = mlx_xpm_file_to_image(game->mlx , "../../imgs/2.xpm", &width, &height);
	game->numbers[3] = mlx_xpm_file_to_image(game->mlx , "../../imgs/3.xpm", &width, &height);
	game->numbers[4] = mlx_xpm_file_to_image(game->mlx , "../../imgs/4.xpm", &width, &height);
	game->numbers[5] = mlx_xpm_file_to_image(game->mlx , "../../imgs/5.xpm", &width, &height);
	game->numbers[6] = mlx_xpm_file_to_image(game->mlx , "../../imgs/6.xpm", &width, &height);
	game->numbers[8] = mlx_xpm_file_to_image(game->mlx , "../../imgs/8.xpm", &width, &height);
	game->numbers[7] = mlx_xpm_file_to_image(game->mlx , "../../imgs/7.xpm", &width, &height);
	game->numbers[9] = mlx_xpm_file_to_image(game->mlx , "../../imgs/9.xpm", &width, &height);
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

void init_header(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->counter_img, 0 , 0);
	int dx = 600;
	int map_width_in_pixels = game->map_width * TILE_SIZE;
	while (dx < map_width_in_pixels)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->background_yellow, dx , 0);
		dx += 600;
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
	mlx_hook(game.win, 17, 0, free_leaks_mlx, &game);
	mlx_loop_hook(game.mlx, animate_enemy, &game);
	init_header(&game);
	display_map(&game);
	mlx_loop(game.mlx);
	return (0);
}