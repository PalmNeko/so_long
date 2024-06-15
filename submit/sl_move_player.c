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

#include "sl.h"
#include <limits.h>

void	sl_set_direction(t_sl_player *player, enum e_direction direction);

int	sl_move_player(t_sl_this *sl, t_sl_player *player, int x, int y)
{
	if (player->aim_x != player->now_x)
		return (-1);
	if (player->aim_y != player->now_y)
		return (-1);
	if (player->x < x)
		sl_set_direction(player, RIGHT);
	else if (player->y < y)
		sl_set_direction(player, DOWN);
	else if (player->x > x)
		sl_set_direction(player, LEFT);
	else if (player->y > y)
		sl_set_direction(player, UP);
	if (sl_detect_collision_map(sl->map, x, y) == true)
		return (-1);
	player->x = x;
	player->y = y;
	player->aim_x = player->x * sl->block_width;
	player->aim_y = player->y * sl->block_height;
	return (0);
}

void	sl_set_direction(t_sl_player *player, enum e_direction direction)
{
	int	iter;

	iter = (*player->now_flipbook)->iter;
	player->direction = direction;
	if (direction == RIGHT)
		player->now_flipbook = &player->right_flipbook;
	else if (direction == DOWN)
		player->now_flipbook = &player->down_flipbook;
	else if (direction == LEFT)
		player->now_flipbook = &player->left_flipbook;
	else if (direction == UP)
		player->now_flipbook = &player->up_flipbook;
	mxw_reset_flipbook(*player->now_flipbook);
	mxw_flip_flipbbook(*player->now_flipbook, iter);
	return ;
}
