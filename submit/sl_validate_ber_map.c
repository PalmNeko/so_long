/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_validate_ber_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:40:57 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/17 17:40:57 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "sl_errors.h"
#include "sl.h"

bool	sl_validate_ber_map_size(char **ber_data);
bool	sl_validate_ber_map_chr_count(char **ber_data);

bool	sl_validate_ber_map(char **ber_data)
{
	if (sl_validate_ber_chr(ber_data, "10PCE") == false)
		return (sl_put_error(SL_EMAP_PARSE), false);
	if (sl_validate_ber_map_size(ber_data) == false)
		return (false);
	if (sl_validate_ber_map_chr_count(ber_data) == false)
		return (false);
	if (sl_validate_ber_end_newline(ber_data) == false)
		return (sl_put_error(SL_EMAP_MUST_END_NEWLINE), false);
	if (sl_int_ber_chr_count(ber_data, 'P') == 0)
		return (sl_put_error(SL_EMAP_MUST_INCLUDE_PLAYER), false);
	if (sl_validate_ber_map_surrounded(ber_data) == false)
		return (sl_put_error(SL_EMAP_MUST_SURROUND), false);
	return (true);
}

bool	sl_validate_ber_map_size(char **ber_data)
{
	bool 	(*const validate_functions[])(char **) = {
		sl_validate_ber_map_width,
		sl_validate_ber_map_height
	};
	int		*error_values;
	size_t	index;

	error_values = (int []) {
		SL_EMAP_WIDTH,
		SL_ENONE,
	};
	index = 0;
	while (index < sizeof(validate_functions) / sizeof(validate_functions[0]))
	{
		if (validate_functions[index](ber_data) == false)
		{
			sl_put_error(error_values[index]);
			return (false);
		}
		index++;
	}
	return (true);
}

bool	sl_validate_ber_map_chr_count(char **ber_data)
{
	if (sl_int_ber_chr_count(ber_data, 'P') >= 2)
		return (sl_put_error(SL_EMAP_DUPLICATED_PLAYER), false);
	if (sl_int_ber_chr_count(ber_data, 'E') >= 2)
		return (sl_put_error(SL_EMAP_DUPLICATED_EXIT), false);
	if (sl_int_ber_chr_count(ber_data, 'P') == 0)
		return (sl_put_error(SL_EMAP_MUST_INCLUDE_PLAYER), false);
	if (sl_int_ber_chr_count(ber_data, '1') == 0)
		return (sl_put_error(SL_EMAP_MUST_INCLUDE_WALL), false);
	if (sl_int_ber_chr_count(ber_data, 'C') == 0)
		return (sl_put_error(SL_EMAP_MUST_INCLUDE_COLLECTIBLE), false);
	if (sl_int_ber_chr_count(ber_data, '0') == 0)
		return (sl_put_error(SL_EMAP_MUST_INCLUDE_FREESPACE), false);
	if (sl_int_ber_chr_count(ber_data, 'E') == 0)
		return (sl_put_error(SL_EMAP_MUST_INCLUDE_EXIT), false);
	return (true);
}
