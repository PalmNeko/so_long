/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:27:18 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/10 17:27:18 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_types.h"

void	sl_move_player(t_sl_this *sl, int x, int y)
{
	if (! (0 <= x && x < sl->map->width)
		|| ! (0 <= y && y < sl->map->height))
		return ;
	if (sl->player->aim_x != sl->player->now_x)
		return ;
	if (sl->player->aim_y != sl->player->now_y)
		return ;
	if (sl->player->x < x)
		sl->player->direction = RIGHT;
	else if (sl->player->y < y)
		sl->player->direction = DOWN;
	else if (sl->player->x > x)
		sl->player->direction = LEFT;
	else if (sl->player->y > y)
		sl->player->direction = UP;
	sl->player->x = x;
	sl->player->y = y;
	sl->player->aim_x = sl->player->x * sl->block_width;
	sl->player->aim_y = sl->player->y * sl->block_width;
}
