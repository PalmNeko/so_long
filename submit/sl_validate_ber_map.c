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

bool	sl_validate_ber_map(char **ber_data)
{
	if (sl_validate_ber_map_size(ber_data) == false)
		return (false);
	if (sl_validate_ber_end_newline(ber_data) == false)
		return (sl_put_error(SL_EMAP_MUST_END_NEWLINE), false);
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
	}
	return (true);
}
