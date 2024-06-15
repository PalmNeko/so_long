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

static int	delete_item(t_sl_this *sl, t_sl_fmp_param *param);

void	sl_update_map(t_sl_this *sl)
{
	sl_foreach_map((t_sl_foreach_map_param []){{
		.f = delete_item,
		.map = sl->map,
		.result = NULL,
		.your_param = sl,
	}});
}

static int	delete_item(t_sl_this *sl, t_sl_fmp_param *param)
{
	if (param->map->fields[param->index_y][param->index_x] == ITEM)
	{
		if (param->index_y * sl->block_height == sl->player->now_y
			&& param->index_x * sl->block_width == sl->player->now_x)
		{
			param->map->fields[param->index_y][param->index_x] = NONE;
			sl->item_count += 1;
		}
	}
	return (0);
}
