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

void	sl_set_direction(t_sl_player *player, enum e_direction direction);

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
		sl_set_direction(sl->player, RIGHT);
	else if (sl->player->y < y)
		sl_set_direction(sl->player, DOWN);
	else if (sl->player->x > x)
		sl_set_direction(sl->player, LEFT);
	else if (sl->player->y > y)
		sl_set_direction(sl->player, UP);
	mxw_reset_flipbook(*sl->player->now_flipbook);
	sl->player->x = x;
	sl->player->y = y;
	sl->player->aim_x = sl->player->x * sl->block_width;
	sl->player->aim_y = sl->player->y * sl->block_width;
}

void	sl_set_direction(t_sl_player *player, enum e_direction direction)
{
	player->direction = direction;
	if (direction == RIGHT)
		player->now_flipbook = &player->right_flipbook;
	else if (direction == DOWN)
		player->now_flipbook = &player->down_flipbook;
	else if (direction == LEFT)
		player->now_flipbook = &player->left_flipbook;
	else if (direction == UP)
		player->now_flipbook = &player->up_flipbook;
	return ;
}
