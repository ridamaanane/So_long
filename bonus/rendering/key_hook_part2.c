/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_part2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaanane <rmaanane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:27:34 by rmaanane          #+#    #+#             */
/*   Updated: 2025/03/12 02:51:09 by rmaanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_hook(int keycode, t_game *game)
{
	int	new_position_x;
	int	new_position_y;

	update_player_direction(keycode, game, &new_position_y, &new_position_x);
	handle_game_over(keycode, game);
	if (game->map[new_position_y][new_position_x] == 'C')
	handle_collectible(game, new_position_y, new_position_x);
	if (game->map[new_position_y][new_position_x] == 'E')
		handle_exit_door(game, new_position_y, new_position_x);
	handle_player_movement(game, new_position_y, new_position_x);
	display_map(game);
	return (0);
}
