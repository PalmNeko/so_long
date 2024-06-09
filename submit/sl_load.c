/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:15:53 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/09 17:24:03 by tookuyam         ###   ########.fr       */
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
	sl->sprite_sheet = sl_load_sprite_sheet(mxw);
	if (sl->sprite_sheet == NULL)
		return (-1);
	sl->player = sl_new_player(sl);
	if (sl->player == NULL)
		return (-1);
	sl->wall = mxw_cut_spritesheet(mxw, sl->sprite_sheet, 0, 14);
	if (sl->wall == NULL)
		return (-1);
	sl->road = mxw_cut_spritesheet(mxw, sl->sprite_sheet, 9, 16);
	if (sl->wall == NULL)
		return (-1);
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
	t_mxw_image	*block_image;

	if (param->image_x % sl->block_width != 0
		|| param->image_y % sl->block_height != 0)
		return (0);
	map_x = param->image_x / sl->block_width;
	map_y = param->image_y / sl->block_height;
	if (map_x > sl->map->width || map_y > sl->map->height)
		return (0);
	block_image = NULL;
	if (sl->map->fields[map_y][map_x] == WALL)
		block_image = sl->wall;
	else if (sl->map->fields[map_y][map_x] == ROAD)
		block_image = sl->road;
	if (block_image != NULL)
		mxw_put_image_to_image(
			param->image, block_image, param->image_x, param->image_y);
	return (0);
}
