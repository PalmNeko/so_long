/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_validate_ber_map_width.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:52:59 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/17 18:52:59 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "sl.h"
bool	sl_validate_ber_map_width(char **ber_data)
{
	int		field_width;

	field_width = sl_get_ber_width(ber_data);
	if (field_width == -2)
		return (false);
	return (true);
}
