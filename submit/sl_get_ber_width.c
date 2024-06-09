/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_get_ber_width.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:07:10 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/09 16:42:25 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include "libft.h"

/**
 * @brief get ber map width.
 * @attention ber width is equal to any line.
 * @return map width. minus value if occur error.
*/
int	sl_get_ber_width(char **ber_data)
{
	size_t		field_width;
	char		**iter;

	iter = ber_data;
	field_width = 0;
	if (*iter != NULL)
		field_width = ft_strlen(*iter);
	if (field_width > INT_MAX || field_width <= 1)
		return (-1);
	field_width -= 1;
	while (*iter != NULL)
	{
		if (field_width != ft_strlen(*iter) - 1)
			return (-1);
		iter++;
	}
	return ((int)field_width);
}
