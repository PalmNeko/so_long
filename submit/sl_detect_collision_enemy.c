/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_detect_collision_enemy.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 03:54:48 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/16 03:54:48 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "sl_types.h"

bool	sl_detect_collision_enemy(t_sl_player *player, t_sl_player *enemy)
{
	if (player->now_x == enemy->now_x
		&& player->now_y == enemy->now_y)
		return (true);
	return (false);
}
