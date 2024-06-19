/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_move_player_wrap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 04:30:06 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/16 04:30:06 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"
#include <limits.h>

void	sl_move_player_wrap(
			t_sl_this *sl, t_sl_player *player, t_direction direct)
{
	int	x;
	int	y;

	x = sl->player->x;
	y = sl->player->y;
	if (direct == LEFT)
		x += -1;
	if (direct == UP)
		y += -1;
	if (direct == RIGHT)
		x += 1;
	if (direct == DOWN)
		y += 1;
	if (sl_move_player(sl, player, x, y) != 0)
		return ;
	if (sl->move_count < INT_MAX)
		sl->move_count += 1;
	sl_print_move_counter(sl->move_count);
}
