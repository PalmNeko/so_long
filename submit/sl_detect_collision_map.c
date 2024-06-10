/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_detect_collision_map.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 02:41:12 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/11 02:41:12 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "sl_types.h"

bool	sl_detect_collision_map(t_sl_map *map, int x, int y)
{
	if (! (0 <= x && x < map->width))
		return (true);
	if (! (0 <= y && y < map->height))
		return (true);
	if (map->fields[y][x] == WALL)
		return (true);
	else
		return (false);
}
