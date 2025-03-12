/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaanane <rmaanane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 20:57:22 by rmaanane          #+#    #+#             */
/*   Updated: 2025/03/12 02:56:03 by rmaanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	count_lines(char *file_path)
{
	char	*line;
	int		line_count;
	int		fd;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		perror(file_path);
		exit(1);
	}
	line = get_next_line(fd);
	line_count = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		line_count++;
	}
	close(fd);
	return (line_count);
}

char	**alloc_map(int fd, int nbr_lines)
{
	int		i;
	char	**map;
	char	*line;

	map = malloc(sizeof(char *) * (nbr_lines + 1));
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	if (!line)
	{
		free(map);
		exit(1);
	}
	i = 0;
	while (line)
	{
		map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return (map);
}

size_t	no_line_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	**read_map(t_game *game, char *file_path)
{
	char	**map;

	int (fd), (nbr_lines);
	nbr_lines = count_lines(file_path);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		perror(file_path);
		exit(1);
	}
	map = alloc_map(fd, nbr_lines);
	game->map_width = no_line_strlen(map[0]);
	game->map_height = nbr_lines;
	game->map = map;
	if (check_rectangular(game, game->map_width, game->map_height) == 0
		|| validate_map_structure(game, game->map_width, game->map_height) == 0
		|| check_required_elements(game, game->map_width, game->map_height) == 0
		|| check_walls(game, game->map_width, game->map_height) == 0)
	{
		free_map(map);
		close(fd);
		exit(1);
	}
	check_path(game);
	return (close(fd), map);
}