/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_put_image_to_image.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 20:09:32 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/06 16:17:19 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mxw.h"
#include <stdio.h>

int	mxw_put_image_to_image(t_mxw_image *canvas, t_mxw_image *image,
		int x, int y)
{
	int	index_x;
	int	index_y;
	int	color;

	index_y = 0;
	while (index_y < image->height)
	{
		index_x = 0;
		while (index_x < image->width)
		{
			color = mxw_pixel_get_from_image(image, index_x, index_y);
			mxw_pixel_put_to_image(canvas, x + index_x, y + index_y, color);
			index_x++;
		}
		index_y++;
	}
	return (0);
}
