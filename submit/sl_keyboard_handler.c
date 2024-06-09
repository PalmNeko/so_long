/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_keyboard_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:15:04 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/09 12:40:43 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"
#include "mxw.h"
#include <stdio.h>

int	sl_keyboard_handler(int keycode, t_sl_this *vars)
{
	if (keycode == KEY_ESC)
		mxw_set_end(vars->mxw);
	if (keycode == KEY_RETURN)
	{
		mxw_flip_flipbbook(*vars->player->now_flipbook, 1);
		mxw_put_image_to_window(vars->so_long_window,
			mxw_get_image_from_flipbook(*vars->player->now_flipbook), 0, 0);
		mxw_flip_screen(vars->so_long_window);
	}
	return (0);
}
