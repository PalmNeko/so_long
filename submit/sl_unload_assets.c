/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_unload_assets.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:26:41 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/08 14:37:23 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mxw.h"

void	sl_unload_assets(t_sl_this *sl)
{
	sl_destroy_player(sl->player);
	mxw_destroy_spritesheet(sl->sprite_sheet);
}
