/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_destroy_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:10:56 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/08 13:13:44 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mxw.h"
#include "sl.h"

void	sl_destroy_player(t_sl_player *player)
{
	mxw_destroy_flipbook(player->left_flipbook);
	mxw_destroy_flipbook(player->up_flipbook);
	mxw_destroy_flipbook(player->right_flipbook);
	mxw_destroy_flipbook(player->down_flipbook);
	free(player);
}
