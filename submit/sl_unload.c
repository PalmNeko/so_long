/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_unload.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:26:24 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/09 16:36:24 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

void	sl_unload(t_sl_this *sl)
{
	sl_destroy_map(sl->map);
	sl_destroy_player(sl->player);
	mxw_destroy_spritesheet(sl->sprite_sheet);
}
