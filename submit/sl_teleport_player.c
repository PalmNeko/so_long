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

void	sl_teleport_player(t_sl_this *sl, t_sl_player *player, int x, int y)
{
	if (sl_detect_collision_map(sl->map, x, y) == true)
		return ;
	player->x = x;
	player->y = y;
	player->aim_x = player->x * sl->block_width;
	player->aim_y = player->y * sl->block_height;
	player->now_x = player->aim_x;
	player->now_y = player->aim_y;
	return ;
}
