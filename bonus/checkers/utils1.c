/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:36:40 by akheired          #+#    #+#             */
/*   Updated: 2024/04/25 13:04:57 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	eleft(t_game *map)
{
	if (map->gui_coins == 0)
		finish_game();
	map->gui_map[map->px][map->py] = '0';
	map->gui_map[map->px][map->py - 1] = 'X';
	map->py--;
}

void	eright(t_game *map)
{
	if (map->gui_coins == 0)
		finish_game();
	map->gui_map[map->px][map->py] = '0';
	map->gui_map[map->px][map->py + 1] = 'X';
	map->py++;
}
