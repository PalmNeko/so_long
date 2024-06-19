/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:15:53 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/19 16:46:58 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mxw.h"
#include "sl.h"

int			sl_load_background(t_sl_this *sl);
static int	put_on_block(t_sl_this *sl, t_mxw_fip_param *param);

int	sl_load(t_sl_this *sl)
{
	sl->map = sl_ber_file_to_map(sl->ber_filename);
	if (sl->map == NULL)
		return (-1);
	if (sl_load_assets(sl->mxw, sl) != 0)
		return (-1);
	if (sl_load_background(sl) != 0)
		return (-1);
	return (0);
}

int	sl_load_background(t_sl_this *sl)
{
	sl->background = mxw_new_image(sl->mxw,
			sl->block_width * sl->map->width,
			sl->block_height * sl->map->height);
	if (sl->background == NULL)
		return (-1);
	mxw_foreach_image((t_mxw_foreach_image_param []){{
		.image = sl->background,
		.offset_x = 0,
		.offset_y = 0,
		.width = sl->background->width,
		.height = sl->background->height,
		.result = NULL,
		.your_param = sl,
		.f = put_on_block,
	}});
	sl->counter_header = mxw_xpm_file_to_image(
			sl->mxw, "textures/count_header.xpm");
	if (sl->counter_header == NULL)
		return (-1);
	return (0);
}

static int	put_on_block(t_sl_this *sl, t_mxw_fip_param *param)
{
	int				map_x;
	int				map_y;
	t_sl_background	bg_block_type;

	if (param->image_x % sl->block_width != 0
		|| param->image_y % sl->block_height != 0)
		return (0);
	map_x = param->image_x / sl->block_width;
	map_y = param->image_y / sl->block_height;
	if (map_x > sl->map->width || map_y > sl->map->height)
		return (0);
	mxw_put_image_to_image(param->image,
		sl->bg_block[BG_GRASS], param->image_x, param->image_y);
	bg_block_type = BG_NONE;
	if (sl->map->goal_point.x == map_x && sl->map->goal_point.y == map_y)
		bg_block_type = BG_GOAL;
	else if (sl->map->fields[map_y][map_x] == WALL)
		bg_block_type = BG_WALL;
	else if (sl->map->fields[map_y][map_x] == ROAD)
		bg_block_type = BG_ROAD;
	if (bg_block_type != BG_NONE)
		mxw_put_image_to_image(param->image,
			sl->bg_block[bg_block_type], param->image_x, param->image_y);
	return (0);
}
