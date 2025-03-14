/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaanane <rmaanane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:56:22 by rmaanane          #+#    #+#             */
/*   Updated: 2025/03/13 00:52:18 by rmaanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	check_walls(t_game *game, int width, int height)
{
	int (pos_x), (pos_y);
	height = game->map_height;
	width = game->map_width;
	pos_y = 0;
	while (pos_y < height)
	{
		if (game->map[pos_y][0] != '1' || game->map[pos_y][width - 1] != '1')
		{
			ft_printf("Error\n❌ Wall missing at row [%d].\n", pos_y);
			return (0);
		}
		pos_y++;
	}
	pos_x = 0;
	while (pos_x < width)
	{
		if (game->map[0][pos_x] != '1' || game->map[height - 1][pos_x] != '1')
		{
			ft_printf("Error\n❌ Wall missing at column [%d].\n", pos_x);
			return (0);
		}
		pos_x++;
	}
	return (1);
}
