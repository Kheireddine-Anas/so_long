/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:28:09 by akheired          #+#    #+#             */
/*   Updated: 2024/04/21 23:34:08 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	borders_check(t_game *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->cp_map[i])
	{
		j = 0;
		while (map->cp_map[i][j] && map->cp_map[i][j] != '\n')
		{
			if (map->cp_map[0][j] != '1' || map->cp_map[i][0] != '1' ||
			map->cp_map[map->line - 1][j] != '1' ||
			map->cp_map[i][map->length - 1] != '1')
				printf("GOLK");
			j++;
		}
		i++;
	}
}

void	errors_msg(int msg_num)
{
	if (msg_num == 2)
		write(1, "Error\nCheck Map Elements\n", 26);
	if (msg_num == 3)
		write(1, "Error\nCheck The Map\n", 21);
	if (msg_num == 4)
		write(1, "Error\nCheck The Map Path\n", 21);
	exit(1);
}