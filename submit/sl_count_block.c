/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_count_block.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:49:57 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/15 20:49:57 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"
#include <limits.h>

int	_sl_count_block(t_sl_block_type *block, t_sl_fmp_param *param);

int	sl_count_block(t_sl_map	*map, t_sl_block_type block)
{
	int	cnt;

	cnt = 0;
	sl_foreach_map((t_sl_foreach_map_param []){{
		.f = _sl_count_block,
		.map = map,
		.result = &cnt,
		.your_param = &block,
	}});
	return (cnt);
}

int	_sl_count_block(t_sl_block_type *block, t_sl_fmp_param *param)
{
	int	*cnt;

	cnt = (int *)param->result;
	if (param->map->fields[param->index_y][param->index_x] == *block)
		if (*cnt < INT_MAX)
			*cnt += 1;
	return (0);
}
