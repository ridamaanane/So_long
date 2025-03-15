/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaanane <rmaanane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:40:09 by rmaanane          #+#    #+#             */
/*   Updated: 2025/03/15 00:22:19 by rmaanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

int	validate_map_structure(t_game *game, int width, int height)
{
	int		pos_y;
	int		pos_x;
	char	current_char;

	if (game->map == NULL)
		return (0);
	pos_y = 0;
	while (pos_y < height)
	{
		pos_x = 0;
		while (pos_x < width)
		{
			current_char = game->map[pos_y][pos_x];
			if (!is_valid_char(current_char))
			{
				ft_printf("Error\nInvalid character '%c' found at [%d, %d]\n",
					current_char, pos_y, pos_x);
				return (0);
			}
			pos_x++;
		}
		pos_y++;
	}
	return (1);
}

int	handle_error_character(int count_P, int count_E, int count_C)
{
	int (handle_error_player), (handle_error_exit), (handle_error_collectibles);
	handle_error_player = 0;
	handle_error_exit = 0;
	handle_error_collectibles = 0;
	if (count_P != 1)
	{
		ft_printf("Error\nYou need to write one player in the map\n");
		handle_error_player = 1;
	}
	if (count_E != 1)
	{
		ft_printf("Error\nYou need to write one exit in the map\n");
		handle_error_exit = 1;
	}
	if (count_C < 1)
	{
		ft_printf("Error\nAt least one collectible\n");
		handle_error_collectibles = 1;
	}
	if (handle_error_player == 1 || handle_error_exit == 1
		|| handle_error_collectibles == 1)
		return (0);
	return (1);
}

int	check_required_elements(t_game *game, int width, int height)
{
	char	current_char;

	int (pos_y), (pos_x), (count_P), (count_E), (count_C);
	count_P = 0;
	count_E = 0;
	count_C = 0;
	pos_y = 0;
	while (pos_y < height)
	{
		pos_x = 0;
		while (pos_x < width)
		{
			current_char = game->map[pos_y][pos_x];
			if (current_char == 'P')
				count_P++;
			else if (current_char == 'E')
				count_E++;
			else if (current_char == 'C')
				count_C++;
			pos_x++;
		}
		pos_y++;
	}
	return (handle_error_character(count_P, count_E, count_C));
}
