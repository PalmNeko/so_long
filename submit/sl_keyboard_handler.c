/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_keyboard_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:15:04 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/10 17:47:21 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"
#include "mxw.h"
#include <stdio.h>
#include <stdbool.h>
#include <X11/Xutil.h>

bool is_update(int keycode, int *update_keys, int cnt);

int	sl_keyboard_handler(int keycode, t_sl_this *vars)
{
	int	update_display_keys[] = {
		XK_Return, XK_a, XK_w, XK_d, XK_s};
	if (keycode == XK_Escape)
		mxw_set_end(vars->mxw);
	if (keycode == XK_Return)
		mxw_flip_flipbbook(*vars->player->now_flipbook, 1);
	if (keycode == XK_a)
		sl_move_player(vars, vars->player->x - 1, vars->player->y);
	if (keycode == XK_w)
		sl_move_player(vars, vars->player->x, vars->player->y - 1);
	if (keycode == XK_d)
		sl_move_player(vars, vars->player->x + 1, vars->player->y);
	if (keycode == XK_s)
		sl_move_player(vars, vars->player->x, vars->player->y + 1);
	if (is_update(keycode, update_display_keys,
		sizeof(update_display_keys) / sizeof(int)))
	{
		sl_draw_image(vars);
		mxw_flip_screen(vars->so_long_window);
	}
	return (0);
}

bool is_update(int keycode, int *update_keys, int cnt)
{
	int	index;

	index = 0;
	while (index < cnt)
	{
		if (keycode == update_keys[index])
			return (true);
		index++;
	}
	return (false);
}
