/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_new_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 12:25:28 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/19 16:55:38 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mxw.h"
#include "sl.h"
#include "sl_int.h"
#include "libft.h"

t_mxw_flipbook	*sprite_sheet_to_player_flipbook(
					t_sl_this *sl, int *points, int size);
void			free_images(t_mxw_image **images, size_t size);
int				sl_assign_player_flipbook(t_sl_player *player, t_sl_this *sl);

t_sl_player	*sl_new_player(t_sl_this *sl, int *points_xy[], int size)
{
	t_sl_player	*player;

	player = (t_sl_player *)malloc(sizeof(t_sl_player));
	if (player == NULL)
		return (NULL);
	if (sl_int_assign_player_flipbook(player, sl, points_xy, size) != 0)
		return (free(player), NULL);
	player->direction = RIGHT;
	player->now_flipbook = &player->right_flipbook;
	player->x = 0;
	player->y = 0;
	player->now_x = 0;
	player->now_y = 0;
	player->aim_x = 0;
	player->aim_y = 0;
	return (player);
}
