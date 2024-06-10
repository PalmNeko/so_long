/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_keyboard_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:15:04 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/11 03:04:20 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"
#include "mxw.h"
#include <stdio.h>
#include <stdbool.h>
#include <X11/Xutil.h>

int	sl_keyboard_handler(int keycode, t_sl_this *vars)
{
	if (keycode == XK_Escape)
		mxw_set_end(vars->mxw);
	if (keycode == XK_Return)
		mxw_flip_flipbbook(*vars->player->now_flipbook, 1);
	if (keycode == XK_a || keycode == XK_Left)
		sl_move_player(vars, vars->player->x - 1, vars->player->y);
	if (keycode == XK_w || keycode == XK_Up)
		sl_move_player(vars, vars->player->x, vars->player->y - 1);
	if (keycode == XK_d || keycode == XK_Right)
		sl_move_player(vars, vars->player->x + 1, vars->player->y);
	if (keycode == XK_s || keycode == XK_Down)
		sl_move_player(vars, vars->player->x, vars->player->y + 1);
	return (0);
}
