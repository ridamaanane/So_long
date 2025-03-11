/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectangularity.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaanane <rmaanane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:55:51 by rmaanane          #+#    #+#             */
/*   Updated: 2025/03/11 01:31:33 by rmaanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rendering/so_long_bonus.h"

int	check_rectangular(t_game *game, int width, int height)
{
	int	pos_x;

	game->map_width = no_line_strlen(game->map[0]);
	pos_x = 1;
	while (pos_x < height)
	{
		width = no_line_strlen(game->map[pos_x]);
		if (width != game->map_width)
		{
			ft_printf("Error\nMap is not rectangular\n");
			return (0);
		}
		pos_x++;
	}
	return (1);
}
