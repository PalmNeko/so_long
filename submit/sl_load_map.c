/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_load_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:23:51 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/09 16:25:24 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

int	sl_load_map(t_sl_this *this)
{
	this->map = sl_ber_file_to_map(this->ber_filename);
	if (this->map == NULL)
		return (-1);
}
