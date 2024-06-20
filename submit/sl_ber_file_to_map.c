/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_ber_file_to_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:13:43 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/21 03:00:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "sl.h"

/**
 * @brief load map data from file.
 * @return map file. NULL if an error occurred and set errno.
 * 	ERRORS: ref: open(2), close(2), malloc(3).
 * @note ber file is so long map file.
*/
t_sl_map	*sl_ber_file_to_map(char *ber_filename)
{
	t_sl_map	*sl_map;
	int			fd;

	fd = open(ber_filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	sl_map = sl_ber_fd_to_map(fd);
	if (close(fd) == -1)
		return (sl_destroy_map(sl_map), NULL);
	return (sl_map);
}
