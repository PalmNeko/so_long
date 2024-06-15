/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_unload.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:26:24 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/15 16:00:32 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

void	sl_unload(t_sl_this *sl)
{
	size_t	index;

	sl_destroy_map(sl->map);
	sl_destroy_player(sl->player);
	index = 0;
	while (index < MAX_BG_BLOCK)
	{
		mxw_destroy_image(sl->bg_block[index]);
		index++;
	}
	mxw_destroy_image(sl->img_item);
	mxw_destroy_image(sl->background);
	mxw_destroy_spritesheet(sl->sprite_sheet);
}
