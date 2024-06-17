/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_validate_ber_end_newline.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:14:44 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/17 17:14:44 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>
#include "sl.h"


int	_sl_validate_ber_end_newline(t_sl_fb_param *param, void *p, bool *validate_result);

bool	sl_validate_ber_end_newline(char **ber_data)
{
	bool	validate_result;

	validate_result = true;
	sl_foreach_ber(
		ber_data,
		_sl_validate_ber_end_newline,
		NULL,
		&validate_result);
	return (validate_result);
}

int	_sl_validate_ber_end_newline(t_sl_fb_param *param, void *p, bool *validate_result)
{
	int		x;
	int		y;
	char	**ber_data;

	(void)p;
	ber_data = param->ber_data;
	x = param->idx_x;
	y = param->idx_y;
	if (ber_data[y][x + 1] == '\0')
	{
		if (ber_data[y][x] != '\n')
		{
			*validate_result = false;
			return (-1);
		}
	}
	return (0);
}
