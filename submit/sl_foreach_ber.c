/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_foreach_ber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:16:00 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/17 17:16:00 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>
#include "sl_param.h"

/**
 * @brief foreach ber_data
 * @param f is called about like f(t_sl_fb_param param, void *your_param);
 * break loop if function f return not 0.
 * @return always NULL (for extension)
 */
void	*sl_foreach_ber(char **ber_data, int (*f)(), void *your_param)
{
	int				x;
	int				y;
	t_sl_fb_param	param;

	param.ber_data = ber_data;
	y = 0;
	while (ber_data[y] != NULL)
	{
		param.idx_y = y;
		x = 0;
		while (ber_data[y][x] != '\0')
		{
			param.idx_x = x;
			if (f(&param, your_param) != 0)
				return (NULL);
			x++;
		}
		y++;
	}
	return (NULL);
}
