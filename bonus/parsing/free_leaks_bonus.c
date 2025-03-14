/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_leaks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaanane <rmaanane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:58:44 by rmaanane          #+#    #+#             */
/*   Updated: 2025/03/13 00:52:23 by rmaanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	free_leaks_arr_imgs(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(game->mlx, game->player_imgs[i++]);
	}
	i = 0;
	while (i < 2)
	{
		mlx_destroy_image(game->mlx, game->door_imgs[i++]);
	}
	i = 0;
	while (i < 6)
	{
		mlx_destroy_image(game->mlx, game->enemy_imgs[i++]);
	}
	i = 0;
	while (i < 10)
	{
		mlx_destroy_image(game->mlx, game->numbers[i++]);
	}
}

int	free_leaks_mlx(t_game *game, char *msg)
{
	mlx_destroy_image(game->mlx, game->wall_img);
	mlx_destroy_image(game->mlx, game->floor_img);
	mlx_destroy_image(game->mlx, game->collectible_img);
	mlx_destroy_image(game->mlx, game->counter_img);
	mlx_destroy_image(game->mlx, game->background_yellow);
	free_leaks_arr_imgs(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game->map);
	write(1, msg, ft_strlen(msg));
	exit(0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}
