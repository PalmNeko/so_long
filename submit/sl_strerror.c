/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_strerror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 05:21:31 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/16 05:21:31 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "sl_errors.h"

char	*sl_strerror_must_include(int sl_errno);

char	*sl_strerror(int sl_errno)
{
	if (sl_errno == SL_EMAP_WIDTH)
		return ("map width must be aligned.");
	else if (sl_errno == SL_EMAP_PARSE)
		return ("cannot parse character.");
	else if (sl_errno == SL_EMAP_DUPLICATED_PLAYER)
		return ("'P' must not be duplicated.");
	else if (sl_errno == SL_EMAP_DUPLICATED_EXIT)
		return ("'E' must not be duplicated.");
	else if (sl_errno == SL_EMAP_MUST_SURROUND)
		return ("map must be surrounded by '1'.");
	else if (sl_errno == SL_EMAP_MUST_END_NEWLINE)
		return ("map must be terminated newline.");
	else if (sl_errno == SL_EMAP_CANT_REACH)
		return ("player cant reach exit or every collectible.");
	else
		return (sl_strerror_must_include(sl_errno));
}

char	*sl_strerror_must_include(int sl_errno)
{
	if (sl_errno == SL_EMAP_MUST_INCLUDE_WALL)
		return ("map must be included '1' at least one.");
	else if (sl_errno == SL_EMAP_MUST_INCLUDE_COLLECTIBLE)
		return ("map must be included 'C' at least one.");
	else if (sl_errno == SL_EMAP_MUST_INCLUDE_FREESPACE)
		return ("map must be included '0' at least one.");
	else if (sl_errno == SL_EMAP_MUST_INCLUDE_PLAYER)
		return ("map must be included 'P' at least one.");
	else if (sl_errno == SL_EMAP_MUST_INCLUDE_EXIT)
		return ("map must be included 'E' at least one.");
	else
		return (NULL);
}
