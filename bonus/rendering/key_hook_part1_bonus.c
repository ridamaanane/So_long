/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_part1_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaanane <rmaanane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:19:26 by rmaanane          #+#    #+#             */
/*   Updated: 2025/03/13 21:28:58 by rmaanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	handle_player_movement(t_game *game, int new_position_y,
		int new_position_x)
{
	if (game->map[new_position_y][new_position_x] != '1')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[new_position_y][new_position_x] = 'P';
		game->player_x = new_position_x;
		game->player_y = new_position_y;
		game->key_count++;
		rander_steps_counter(game);
		ft_printf("keys pressed: %d\n", game->key_count);
	}
}

int	handle_game_over(int keycode, t_game *game, int new_position_y,
		int new_position_x)
{
	if (keycode == ESC_KEY)
		free_leaks_mlx(game, "Game exited successfully!\n");
	if (game->map[new_position_y][new_position_x] == 'K')
	{
		ft_printf("-------------------------------------------------\n");
		ft_printf("|      ❌❌❌  You lost! Game closing  ❌❌❌   |\n");
		ft_printf("|     You failed to reach the exit...           |\n");
		ft_printf("|     Better luck next time!                    |\n");
		ft_printf("|     💡 Try again and improve your strategy!   |\n");
		ft_printf("-------------------------------------------------\n");
		free_leaks_mlx(game, "\n");
	}
	return (0);
}

void	handle_collectible(t_game *game, int new_position_y, int new_position_x)
{
	if (game->map[new_position_y][new_position_x] == 'C')
	{
		game->map[new_position_y][new_position_x] = '0';
		game->collected++;
		if (game->collected == game->total_collectibles)
		{
			game->door_current_img = 1;
			write(1, "Congrats! The door is now open.\n", 32);
		}
	}
}

void	handle_exit_door(t_game *game, int new_position_y, int new_position_x)
{
	if (game->map[new_position_y][new_position_x] == 'E')
	{
		if (game->collected == game->total_collectibles)
		{
			ft_printf("-------------------------------------------------\n");
			ft_printf("|    🎉🎉🎉  Congratulations!!!!!  🎉🎉🎉       |\n");
			ft_printf("|    You found all collectibles and exit.       |\n");
			ft_printf("|        ✓✓✓✓✓✓✓✓ You won! ✓✓✓✓✓✓✓✓             |\n");
			ft_printf("|       🏆 Can you beat your own record?  %d     |\n",
				game->key_count);
			ft_printf("-------------------------------------------------\n");
			free_leaks_mlx(game, "");
		}
		else if (game->collected != game->total_collectibles)
			write(1, "You need to eat all collectibles first!!...\n", 45);
	}
}

void	update_player_direction(int keycode, t_game *game, int *new_position_y,
		int *new_position_x)
{
	*new_position_x = game->player_x;
	*new_position_y = game->player_y;
	if (keycode == W || keycode == 87 || keycode == UP)
	{
		(*new_position_y)--;
		game->player_current_img = 2;
	}
	if (keycode == S || keycode == 83 || keycode == DOWN)
	{
		(*new_position_y)++;
		game->player_current_img = 3;
	}
	if (keycode == A || keycode == 65 || keycode == LEFT)
	{
		(*new_position_x)--;
		game->player_current_img = 1;
	}
	if (keycode == D || keycode == 68 || keycode == RIGHT)
	{
		(*new_position_x)++;
		game->player_current_img = 0;
	}
}
