/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:13:50 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/16 03:58:41 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mxw_types.h"
#include "sl.h"
#include <mlx.h>

bool	is_gameend(t_sl_this *sl)
{
	t_sl_point	*goal_point;

	goal_point = &sl->map->goal_point;
	return (sl_detect_collision_enemy(sl->player, sl->enemy)
		|| (sl->max_item_count == sl->item_count
		&& goal_point->x * sl->block_width == sl->player->now_x
		&& goal_point->y * sl->block_height == sl->player->now_y));
}

void	put_move_count_text(t_sl_this *sl)
{
	char	*move_count;

	move_count = ft_itoa(sl->move_count);
	if (move_count != NULL)
	{
		mlx_string_put(sl->mxw->mlx,
			sl->so_long_window->mlx_win,
			26, 13,
			create_trgb(0, 0, 0, 0),
			move_count);
	}
	free(move_count);
}

int	sl_loop(t_mxw *mxw, t_sl_this *sl)
{
	(void)mxw;
	sl->game_tick += 1;
	if (sl->game_tick > sl->game_tick_reset_time)
		sl->game_tick = 0;
	sl_update_player(sl->player, sl->game_tick);
	sl_update_player(sl->enemy, sl->game_tick);
	sl_update_map(sl);
	sl_draw_image(sl);
	mxw_flip_screen(sl->so_long_window);
	put_move_count_text(sl);
	if (is_gameend(sl))
		mxw_set_end(mxw);
	return (0);
}
