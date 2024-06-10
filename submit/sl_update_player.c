/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_update_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:00:53 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/10 18:00:53 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_types.h"
#include "libft.h"

void	sl_update_player(t_sl_player *player, size_t game_tick)
{
	int	diff_x;
	int	diff_y;

	if (game_tick % 100 == 0)
		mxw_flip_flipbbook(*player->now_flipbook, 1);
	diff_x = player->aim_x - player->now_x;
	diff_y = player->aim_y - player->now_y;
	if (diff_x == 0 && diff_y == 0)
		return ;
	player->now_x += diff_x / abs(diff_x);
	player->now_y += diff_y / abs(diff_y);
	return ;
}
