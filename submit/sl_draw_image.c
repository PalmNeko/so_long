/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_draw_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:19:58 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/09 17:49:53 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_types.h"

void sl_draw_image(t_sl_this *sl)
{
	mxw_put_image_to_window(sl->so_long_window, sl->background, 0, 0);
	mxw_put_image_to_window(sl->so_long_window,
		mxw_get_image_from_flipbook(*sl->player->now_flipbook), 0, 0);
}
