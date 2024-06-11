/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:13:50 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/11 14:06:02 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mxw_types.h"
#include "sl.h"

bool	is_gameend(t_sl_this *sl)
{
	t_sl_point	*goal_point;

	goal_point = &sl->map->goal_point;
	return (goal_point->x * sl->block_width == sl->player->now_x
		&& goal_point->y * sl->block_height == sl->player->now_y);
}

int	sl_loop(t_mxw *mxw, t_sl_this *loop_args)
{
	(void)mxw;
	loop_args->game_tick += 1;
	if (loop_args->game_tick > loop_args->game_tick_reset_time)
		loop_args->game_tick = 0;
	sl_update_player(loop_args->player, loop_args->game_tick);
	sl_draw_image(loop_args);
	mxw_flip_screen(loop_args->so_long_window);
	if (is_gameend(loop_args))
		mxw_set_end(mxw);
	return (0);
}
