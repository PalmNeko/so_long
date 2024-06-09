/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:15:53 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/09 16:55:35 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mxw.h"
#include "sl.h"

int							sl_load_assets(t_mxw *mxw, t_sl_this *sl);
static t_mxw_spritesheet	*sl_load_sprite_sheet(t_mxw *mxw);

int	sl_load(t_sl_this *sl)
{
	sl->map = sl_ber_file_to_map(sl->ber_filename);
	if (sl->map == NULL)
		return (-1);
	return (sl_load_assets(sl->mxw, sl));
}

int	sl_load_assets(t_mxw *mxw, t_sl_this *sl)
{
	sl->sprite_sheet = sl_load_sprite_sheet(mxw);
	if (sl->sprite_sheet == NULL)
		return (-1);
	sl->player = sl_new_player(sl);
	if (sl->player == NULL)
		return (mxw_destroy_spritesheet(sl->sprite_sheet), -1);
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
