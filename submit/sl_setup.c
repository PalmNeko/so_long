/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:57:48 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/15 17:56:02 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "mxw.h"
#include "sl.h"

int	_destroy(t_sl_this *vars)
{
	mxw_set_end(vars->mxw);
	return (0);
}

t_mxw_image	*output_test_image(t_mxw *mxw);

int	sl_setup(t_mxw *mxw, t_sl_this *setup_args)
{
	t_mxw_window		*so_long_window;

	setup_args->mxw = mxw;
	setup_args->ber_filename = "maps/sample.ber";
	setup_args->block_height = BLOCK_TILE_HEIGHT;
	setup_args->block_width = BLOCK_TILE_WIDTH;
	setup_args->game_tick_reset_time = MAX_GAME_TICK;
	if (sl_load(setup_args) != 0)
		return (-1);
	sl_teleport_player(
		setup_args,
		setup_args->map->player_point.x,
		setup_args->map->player_point.y);
	setup_args->player->now_x = setup_args->player->aim_x;
	setup_args->player->now_y = setup_args->player->aim_y;
	so_long_window = mxw_new_window(mxw,
		WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	if (so_long_window == NULL)
		return (sl_unload(setup_args), -1);
	setup_args->so_long_window = so_long_window;
	sl_draw_image(setup_args);
	mxw_flip_screen(so_long_window);
	mxw_add_event(so_long_window, ON_DESTROY, _destroy, setup_args);
	mxw_add_event(so_long_window, ON_KEYDOWN, sl_keyboard_handler, setup_args);
	return (0);
}
