/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_validate_ber_map_size.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 14:56:37 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/16 06:16:26 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stddef.h>
#include <stdbool.h>
#include "libft.h"
#include "sl_errors.h"
#include "sl.h"

static bool	sl_validate_ber_map_width(char **ber_data);
static bool	sl_validate_ber_map_height(char **ber_data);

bool	sl_validate_ber_map_size(char **ber_data)
{
	if (sl_validate_ber_map_width(ber_data) == false)
		return (false);
	if (sl_validate_ber_map_height(ber_data) == false)
		return (false);
	return (true);
}

static bool	sl_validate_ber_map_width(char **ber_data)
{
	int		field_width;

	field_width = sl_get_ber_width(ber_data);
	if (field_width == -2)
		return (sl_put_error(SL_EMAP_WIDTH), false);
	return (true);
}

static bool	sl_validate_ber_map_height(char **ber_data)
{
	int		field_height;

	field_height = sl_get_ber_height(ber_data);
	if (field_height < 0)
		return (false);
	return (true);
}
