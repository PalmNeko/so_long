/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_pixel_get_from_image.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 20:12:38 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/02 20:15:41 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "mxw_types.h"

int	mxw_pixel_get_from_image(t_mxw_image *data, int x, int y)
{
	char	*dst;
	size_t	index;

	index = y * data->line_length + x * (data->bits_per_pixel / 8);
	dst = data->addr + index;
	return (*(unsigned int *)dst);
}
