/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaanane <rmaanane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:35:24 by rmaanane          #+#    #+#             */
/*   Updated: 2025/03/11 01:31:09 by rmaanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rendering/so_long_bonus.h"

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

int	check_file_name(char *file_path)
{
	int	i;

	i = ft_strlen(file_path);
	if (i < 4 || ft_strcmp(file_path + i - 4, ".ber") != 0)
	{
		ft_printf("Error\n❌ Invalid file name!\n");
		ft_printf("👉 Please provide a valid map '.ber' extension.\n");
		return (0);
	}
	return (1);
}
