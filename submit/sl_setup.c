/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:57:48 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/15 19:40:08 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "mxw.h"
#include "sl.h"

int	_destroy(t_sl_this *sl)
{
	mxw_set_end(sl->mxw);
	return (0);
}

t_mxw_image	*output_test_image(t_mxw *mxw);

int	sl_setup(t_mxw *mxw, t_sl_this *sl)
{
	t_mxw_window		*so_long_window;

	sl->mxw = mxw;
	sl->ber_filename = "maps/sample.ber";
	sl->block_height = BLOCK_TILE_HEIGHT;
	sl->block_width = BLOCK_TILE_WIDTH;
	sl->game_tick_reset_time = MAX_GAME_TICK;
	if (sl_load(sl) != 0)
		return (-1);
	sl_teleport_player(
		sl,
		sl->map->player_point.x,
		sl->map->player_point.y);
	sl->player->now_x = sl->player->aim_x;
	sl->player->now_y = sl->player->aim_y;
	so_long_window = mxw_new_window(mxw,
		WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	if (so_long_window == NULL)
		return (sl_unload(sl), -1);
	sl->so_long_window = so_long_window;
	sl_draw_image(sl);
	mxw_flip_screen(so_long_window);
	mxw_add_event(so_long_window, ON_DESTROY, _destroy, sl);
	mxw_add_event(so_long_window, ON_KEYDOWN, sl_keyboard_handler, sl);
	return (0);
}
