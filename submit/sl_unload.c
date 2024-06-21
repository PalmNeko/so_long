/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_unload.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:26:24 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/22 00:08:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

void	sl_unload(t_sl_this *sl)
{
	size_t	index;

	sl_destroy_map(sl->map);
	sl_destroy_player(sl->player);
	sl_destroy_player(sl->enemy);
	index = 0;
	while (index < MAX_BG_BLOCK)
	{
		mxw_destroy_image(sl->bg_block[index]);
		index++;
	}
	mxw_destroy_image(sl->img_item);
	mxw_destroy_image(sl->background);
	mxw_destroy_image(sl->counter_header);
	mxw_destroy_spritesheet(sl->sprite_sheet);
	sl_init_sl_this(sl);
}
