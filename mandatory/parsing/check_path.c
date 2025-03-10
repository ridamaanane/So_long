/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaanane <rmaanane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:54:35 by rmaanane          #+#    #+#             */
/*   Updated: 2025/03/10 21:55:38 by rmaanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rendering/so_long.h"

char	**duplicate_map(t_game *game)
{
	char	**dup_map;
	int		y;

	dup_map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!dup_map)
		exit(1);
	y = 0;
	while (y < game->map_height)
	{
		dup_map[y] = ft_strdup(game->map[y]);
		if (!dup_map[y])
			exit(1);
		y++;
	}
	dup_map[y] = NULL;
	return (dup_map);
}

void	ft_flood_fill(char **map, int x, int y)
{
	if (map[y][x] == 'V' || map[y][x] == '1')
		return ;
	map[y][x] = 'V';
	ft_flood_fill(map, x + 1, y);
	ft_flood_fill(map, x - 1, y);
	ft_flood_fill(map, x, y + 1);
	ft_flood_fill(map, x, y - 1);
}

void	find_position_player(t_game *game, int *position_x, int *position_y)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'P')
			{
				*position_x = x;
				*position_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	check_path(t_game *game)
{
	char	**dup_map;
	int		x;
	int		y;

	dup_map = duplicate_map(game);
	find_position_player(game, &x, &y);
	ft_flood_fill(dup_map, x, y);
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (dup_map[y][x] == 'C' || dup_map[y][x] == 'E')
			{
				ft_printf("Error\n❌ No valid path");
				free_map(game->map);
				free_map(dup_map);
				exit(1);
			}
			x++;
		}
		y++;
	}
	free_map(dup_map);
}
