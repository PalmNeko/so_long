/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_int.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 02:04:15 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/16 02:04:15 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_INT_H
# define SL_INT_H

# include "sl_types.h"

int				sl_int_assign_player_flipbook(
					t_sl_player *player,
					t_sl_this *sl,
					int *points_xy[],
					int size);
t_mxw_flipbook	*sl_int_sprite_sheet_to_player_flipbook(
					t_sl_this *sl, int *points, int size);
int				sl_int_ber_chr_count(char **ber_data, char chr);

#endif
