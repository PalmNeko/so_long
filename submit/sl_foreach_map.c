/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_foreach_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:12:19 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/15 16:12:19 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_param.h"

void	*sl_foreach_map(t_sl_foreach_map_param *param)
{
	int	x;
	int	y;

	y = 0;
	while (y < param->map->height)
	{
		x = 0;
		while (x < param->map->width)
		{
			param->f(param->your_param, (t_sl_fmp_param []){{
				.index_x = x,
				.index_y = y,
				.map = param->map,
				.result = param->result,
			}});
			x++;
		}
		y++;
	}
	return (param->result);
}
