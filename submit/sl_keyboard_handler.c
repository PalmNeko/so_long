/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_keyboard_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:15:04 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/10 16:50:33 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"
#include "mxw.h"
#include <stdio.h>
#include <X11/Xutil.h>

int	sl_keyboard_handler(int keycode, t_sl_this *vars)
{
	if (keycode == XK_Escape)
		mxw_set_end(vars->mxw);
	if (keycode == XK_Return)
	{
		mxw_flip_flipbbook(*vars->player->now_flipbook, 1);
		sl_draw_image(vars);
		mxw_flip_screen(vars->so_long_window);
	}
	return (0);
}
