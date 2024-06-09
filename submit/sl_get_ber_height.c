/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_get_ber_height.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:12:24 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/09 15:14:32 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <limits.h>
#include <stddef.h>

/**
 * @brief get ber map height.
 * @attention ber height is equal to any line.
 * @return map height. minus value if occur error.
*/
int	sl_get_ber_height(char **ber_data)
{
	size_t		field_height;
	char		**iter;

	iter = ber_data;
	while (*iter != NULL)
		iter++;
	field_height = iter - ber_data;
	if (field_height > INT_MAX)
		return (-1);
	return ((int)field_height);
}
