/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_leaks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaanane <rmaanane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:58:44 by rmaanane          #+#    #+#             */
/*   Updated: 2025/03/15 00:22:37 by rmaanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_leaks_mlx(t_game *game, char *msg)
{
	int	i;

	i = 0;
	mlx_destroy_image(game->mlx, game->wall_img);
	mlx_destroy_image(game->mlx, game->floor_img);
	mlx_destroy_image(game->mlx, game->collectible_img);
	while (i < 4)
	{
		mlx_destroy_image(game->mlx, game->player_imgs[i]);
		i++;
	}
	i = 0;
	while (i < 2)
	{
		mlx_destroy_image(game->mlx, game->door_imgs[i]);
		i++;
	}
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
