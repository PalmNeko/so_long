/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_move_enemy_wrap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 04:37:47 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/16 04:37:47 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdbool.h>
#include "sl.h"

void	sl_move_enemy_wrap(t_sl_this *sl, t_sl_player *enemy)
{
	int	result;
	if (sl->game_tick % 300 != 0)
		return ;
	result = -1;
	if (result == -1 && sl->player->x > enemy->x)
		result = sl_move_player(sl, enemy, enemy->x + 1, enemy->y);
	if (result == -1 && sl->player->x < enemy->x)
		result = sl_move_player(sl, enemy, enemy->x - 1, enemy->y);
	if (result == -1 && sl->player->y > enemy->y)
		result = sl_move_player(sl, enemy, enemy->x, enemy->y + 1);
	if (result == -1 && sl->player->y < enemy->y)
		result = sl_move_player(sl, enemy, enemy->x, enemy->y - 1);
	return ;
}
