/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaanane <rmaanane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:35:24 by rmaanane          #+#    #+#             */
/*   Updated: 2025/03/15 01:47:28 by rmaanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	return (0);
}

int	check_ber(char *file_path)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (file_path[i])
	{
		if (file_path[i] == '.')
			j = i;
		i++;
	}
	return (j);
}

int	check_file_name(char *file_path)
{
	int	i;
	int	j;

	i = ft_strlen(file_path);
	j = check_ber(file_path);
	if (j == 0)
	{
		ft_printf("Error\n❌ Invalid file name!\n");
		ft_printf("👉 Please provide a valid map '.ber' extension.\n");
		return (0);
	}
	if (i >= 4 && ft_strcmp(file_path + i - 5, "/.ber") == 0)
	{
		ft_printf("Error\n❌ Invalid file name!\n");
		ft_printf("👉 Please provide a valid map '.ber' extension.\n");
		return (0);
	}
	if (i < 4 || ft_strcmp(file_path + i - 4, ".ber") != 0)
	{
		ft_printf("Error\n❌ Invalid file name!\n");
		ft_printf("👉 Please provide a valid map '.ber' extension.\n");
		return (0);
	}
	return (1);
}
