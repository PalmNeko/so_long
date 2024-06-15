/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_teleport_random_enemy.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 03:36:23 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/16 03:36:23 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"
#include <stdint.h>

static unsigned int	xorshift(unsigned int seed, unsigned int x);
int 				_sl_teleport_random_player(
						t_sl_this *sl, t_sl_player *player);

void sl_teleport_random_player(t_sl_this *sl, t_sl_player *player)
{
	int		x;
	int		y;

	if (_sl_teleport_random_player(sl, player) == 0)
		return ;
	y = 0;
	while (y < sl->map->height)
	{
		x = 0;
		while (x < sl->map->width)
		{
			if (sl->map->fields[y][x] != WALL)
			{
				sl_teleport_player(sl, player, x, y);
				return ;
			}
			x++;
		}
		y++;
	}
	return ;
}

int _sl_teleport_random_player(t_sl_this *sl, t_sl_player *player)
{
	unsigned int		seed;
	static unsigned int	cnt;
	unsigned int		x;
	unsigned int		y;
	int					index;

	seed = (unsigned int)((uintptr_t)sl->map & 0xFFFFFFFF);
	index = 0;
	while (index < 1000)
	{
		cnt++;
		x = xorshift(seed, cnt) % sl->map->width;
		cnt++;
		y = xorshift(seed, cnt) % sl->map->height;
		if (sl->map->fields[y][x] != WALL)
		{
			sl_teleport_player(sl, player, x, y);
			return (0);
		}
		index++;
	}
	return (-1);
}

static unsigned int	xorshift(unsigned int seed, unsigned int x)
{
	x ^= seed;
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return (x);
}
