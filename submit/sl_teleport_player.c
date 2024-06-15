/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_teleport_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:53:37 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/15 17:53:37 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

void	sl_teleport_player(t_sl_this *sl, int x, int y)
{
	if (sl_detect_collision_map(sl->map, x, y) == true)
		return ;
	sl->player->x = x;
	sl->player->y = y;
	sl->player->aim_x = sl->player->x * sl->block_width;
	sl->player->aim_y = sl->player->y * sl->block_height;
	sl->player->now_x = sl->player->aim_x;
	sl->player->now_y = sl->player->aim_y;
	return ;
}
