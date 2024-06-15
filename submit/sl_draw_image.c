/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_draw_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:19:58 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/16 02:53:18 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

void	sl_draw_map(t_sl_this *sl);
int		draw_objects(t_sl_this *sl, t_sl_fmp_param *param);
void	update_camera(t_sl_this *sl);

void sl_draw_image(t_sl_this *sl)
{
	update_camera(sl);
	sl_draw_map(sl);
	mxw_put_image_to_window(
		sl->so_long_window,
		mxw_get_image_from_flipbook(*sl->player->now_flipbook),
		sl->player->now_x - sl->camera_point.x,
		sl->player->now_y - sl->camera_point.y);
	mxw_put_image_to_window(
		sl->so_long_window,
		mxw_get_image_from_flipbook(*sl->enemy->now_flipbook),
		sl->enemy->now_x - sl->camera_point.x,
		sl->enemy->now_y - sl->camera_point.y);
	mxw_put_image_to_window(sl->so_long_window, sl->counter_header, 0, 0);
}

void	sl_draw_map(t_sl_this *sl)
{
	mxw_put_image_to_window(sl->so_long_window, sl->background, - sl->camera_point.x, - sl->camera_point.y);
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
			x * sl->block_width - sl->camera_point.x,
			y * sl->block_height - sl->camera_point.y);
	}
	return (0);
}

void	update_camera(t_sl_this *sl)
{
	int	max_x;
	int max_y;

	sl->camera_point.x = sl->player->now_x - (sl->so_long_window->width / 2);
	sl->camera_point.y = sl->player->now_y - (sl->so_long_window->height / 2);
	if (sl->camera_point.x < 0)
		sl->camera_point.x = 0;
	if (sl->camera_point.y < 0)
		sl->camera_point.y = 0;
	max_x = sl->map->width * sl->block_width;
	max_y = sl->map->height * sl->block_height;
	if (sl->camera_point.x + sl->so_long_window->width > max_x)
		sl->camera_point.x = max_x - sl->so_long_window->width;
	if (sl->camera_point.y + sl->so_long_window->height > max_y)
		sl->camera_point.y = max_y - sl->so_long_window->height;
	return ;
}
