/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_int_ber_chr_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:59:40 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/17 18:59:40 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

int	_sl_int_ber_chr_count(t_sl_fb_param *param, char *chr, int *cnt);

int	sl_int_ber_chr_count(char **ber_data, char chr)
{
	int	cnt;

	cnt = 0;
	sl_foreach_ber(ber_data, _sl_int_ber_chr_count, &chr, &cnt);
	return (cnt);
}

int	_sl_int_ber_chr_count(t_sl_fb_param *param, char *chr, int *cnt)
{
	int		x;
	int		y;
	char	**ber_data;

	ber_data = param->ber_data;
	x = param->idx_x;
	y = param->idx_y;
	if (ber_data[y][x] == *chr)
		*cnt += 1;
	return (0);
}
