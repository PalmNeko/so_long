/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_draw_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:19:58 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/15 16:23:32 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

void	sl_draw_map(t_sl_this *sl);
int		draw_objects(t_sl_this *sl, t_sl_fmp_param *param);

void sl_draw_image(t_sl_this *sl)
{
	sl_draw_map(sl);
	mxw_put_image_to_window(
		sl->so_long_window,
		mxw_get_image_from_flipbook(*sl->player->now_flipbook),
		sl->player->now_x,
		sl->player->now_y);
}

void	sl_draw_map(t_sl_this *sl)
{
	mxw_put_image_to_window(sl->so_long_window, sl->background, 0, 0);
	sl_foreach_map((t_sl_foreach_map_param []){{
		.f = draw_objects,
		.map = sl->map,
		.result = NULL,
		.your_param = sl,
	}});
}

int	draw_objects(t_sl_this *sl, t_sl_fmp_param *param)
{
	int			x;
	int			y;
	t_sl_map	*map;

	x = param->index_x;
	y = param->index_y;
	map = param->map;
	if (map->fields[y][x] == ITEM)
	{
		mxw_put_image_to_window(sl->so_long_window, sl->img_item,
			x * sl->block_width,
			y * sl->block_height);
	}
	return (0);
}
