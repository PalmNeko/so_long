/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_load_assets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:37:21 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/15 15:37:21 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mxw.h"
#include "sl.h"

static t_mxw_spritesheet	*sl_load_sprite_sheet(t_mxw *mxw);

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
		tmp = mxw_resize_image(mxw, sl->bg_block[bg[index]],
			sl->bg_block[bg[index]]->width * IMAGE_SCALE,
			sl->bg_block[bg[index]]->height * IMAGE_SCALE);
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
