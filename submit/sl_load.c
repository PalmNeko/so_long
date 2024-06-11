/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:15:53 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/11 13:47:22 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mxw.h"
#include "sl.h"

int							sl_load_assets(t_mxw *mxw, t_sl_this *sl);
int							sl_load_background(t_sl_this *this);
static t_mxw_spritesheet	*sl_load_sprite_sheet(t_mxw *mxw);
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

int	sl_load_assets(t_mxw *mxw, t_sl_this *sl)
{
	t_mxw_image		*tmp;
	size_t			index;
	t_sl_background	bg[] = {BG_WALL, BG_ROAD, BG_GRASS, BG_GOAL};
	int				x[] = {0, 9, 10, 6};
	int				y[] = {14, 16, 15, 11};

	sl->sprite_sheet = sl_load_sprite_sheet(mxw);
	if (sl->sprite_sheet == NULL)
		return (-1);
	sl->player = sl_new_player(sl);
	if (sl->player == NULL)
		return (-1);
	index = 0;
	while (index < (sizeof(bg) / sizeof(bg[0])))
	{
		sl->bg_block[bg[index]] = mxw_cut_spritesheet(mxw, sl->sprite_sheet, x[index], y[index]);
		if (sl->bg_block[bg[index]] == NULL)
			return (-1);
		tmp = mxw_resize_image(mxw, sl->bg_block[bg[index]], sl->block_width, sl->block_height);
		if (tmp == NULL)
			return (-1);
		mxw_destroy_image(sl->bg_block[bg[index]]);
		sl->bg_block[bg[index]] = tmp;
		index++;
	}
	return (0);
}

static t_mxw_spritesheet	*sl_load_sprite_sheet(t_mxw *mxw)
{
	t_mxw_image			*textures;
	t_mxw_spritesheet	*sprite_sheet;

	textures = mxw_xpm_file_to_image(mxw, "textures/textures.xpm");
	if (textures == NULL)
		return (NULL);
	sprite_sheet = mxw_new_spritesheet(mxw, textures, 16, 16);
	mxw_destroy_image(textures);
	if (sprite_sheet == NULL)
		return (NULL);
	return (sprite_sheet);
}

int	sl_load_background(t_sl_this *this)
{
	this->background = mxw_new_image(this->mxw,
		this->block_width * this->map->width,
		this->block_height * this->map->height);
	if (this->background == NULL)
		return (-1);
	mxw_foreach_image((t_mxw_foreach_image_param []) {{
		.image = this->background,
		.offset_x = 0,
		.offset_y = 0,
		.width = this->background->width,
		.height = this->background->height,
		.result = NULL,
		.your_param = this,
		.f = put_on_block,
	}});
	return (0);
}

static int	put_on_block(t_sl_this *sl, t_mxw_fip_param *param)
{
	int		map_x;
	int		map_y;
	t_sl_background bg_block_type;

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
