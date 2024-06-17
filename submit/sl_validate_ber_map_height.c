/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_validate_ber_map_height.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:52:41 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/17 18:52:41 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "sl.h"

bool	sl_validate_ber_map_height(char **ber_data)
{
	int		field_height;

	field_height = sl_get_ber_height(ber_data);
	if (field_height < 0)
		return (false);
	return (true);
}
