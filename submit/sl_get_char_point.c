/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_get_char_point.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:36:29 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/19 14:39:50 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl_types.h"

t_sl_point	sl_get_char_point(char **ber_data, char c)
{
	int	y;
	int	x;

	y = 0;
	while (ber_data[y] != NULL)
	{
		x = 0;
		while (ber_data[y][x] != '\0')
		{
			if (ber_data[y][x] == c)
				return ((t_sl_point){.x = x, .y = y});
			x++;
		}
		y++;
	}
	return ((t_sl_point){.x = 0, .y = 0});
}
