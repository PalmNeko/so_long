/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_put_image_to_image.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 20:09:32 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/09 17:47:41 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mxw.h"
#include <stddef.h>

static int	__copy_pixel(t_mxw_image *put_image, t_mxw_fip_param *args);

int	mxw_put_image_to_image(t_mxw_image *canvas, t_mxw_image *image,
		int x, int y)
{
	mxw_foreach_image((t_mxw_foreach_image_param []){{
		.image = canvas,
		.f = __copy_pixel,
		.width = image->width,
		.height = image->height,
		.offset_x = x,
		.offset_y = y,
		.result = NULL,
		.your_param = image}});
	return (0);
}

static int	__copy_pixel(t_mxw_image *put_image, t_mxw_fip_param *args)
{
	int	color;

	color = mxw_pixel_get_from_image(put_image, args->index_x, args->index_y);
	mxw_pixel_put_to_image(args->image, args->image_x, args->image_y, color);
	return (0);
}
