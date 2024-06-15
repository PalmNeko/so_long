/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_int_assign_player_flipbook.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 02:00:23 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/16 02:00:23 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_int.h"
#include "sl_types.h"

int	sl_int_assign_player_flipbook(
		t_sl_player *player, t_sl_this *sl, int *points_xy[], int size)
{
	int				index;
	t_mxw_flipbook	***flipbooks;

	flipbooks = (t_mxw_flipbook **[4]){
		&player->down_flipbook, &player->up_flipbook,
		&player->right_flipbook, &player->left_flipbook};
	index = 0;
	while (index < 4)
	{
		*flipbooks[index] = sl_int_sprite_sheet_to_player_flipbook(
			sl, points_xy[index], size);
		if (*flipbooks[index] == NULL)
		{
			while (index >= 0)
			{
				mxw_destroy_flipbook(*flipbooks[index]);
				index--;
			}
			return (-1);
		}
		index++;
	}
	return (0);
}
