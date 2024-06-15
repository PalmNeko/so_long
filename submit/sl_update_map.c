/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_update_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:27:58 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/15 16:27:58 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

void	sl_update_map(t_sl_this *sl)
{
	if (sl->map->fields[sl->player->y][sl->player->x] == ITEM)
	{
		if (sl->player->y * sl->block_height == sl->player->now_y
			&& sl->player->x * sl->block_width == sl->player->now_x)
		{
			sl->map->fields[sl->player->y][sl->player->x] = NONE;
			sl->item_count += 1;
		}
	}
}
