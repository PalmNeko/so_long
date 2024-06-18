/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_validate_chr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 00:41:29 by marvin            #+#    #+#             */
/*   Updated: 2024/06/19 00:41:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>
#include "sl.h"
#include "libft.h"

int	_sl_validate_chr(t_sl_fb_param *param, void *p, bool *validate_result);

bool	sl_validate_chr(char **ber_data)
{
	bool	validate_result;

	validate_result = true;
	sl_foreach_ber(
		ber_data,
		_sl_validate_chr,
		NULL,
		&validate_result);
	return (validate_result);
}

int	_sl_validate_chr(t_sl_fb_param *param, void *p, bool *validate_result)
{
	int		x;
	int		y;
	char	**ber_data;

	(void)p;
	ber_data = param->ber_data;
	x = param->idx_x;
	y = param->idx_y;
	if (ber_data[y][x] == '\n' && ber_data[y][x + 1] == '\0')
		return (0);
	if (! ft_includes(ber_data[y][x], "10PCE"))
	{
		*validate_result = false;
		return (-1);
	}
	return (0);
}
