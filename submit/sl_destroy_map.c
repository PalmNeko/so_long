/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_destroy_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:49:23 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/21 00:10:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sl.h"

void	sl_destroy_map(t_sl_map *map)
{
	int	index;

	index = 0;
	if (map == NULL)
		return ;
	while (index < map->height)
	{
		free(map->fields[index]);
		index++;
	}
	free(map->fields);
	free(map);
}
