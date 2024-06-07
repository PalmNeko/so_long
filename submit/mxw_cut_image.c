/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_cut_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:54:58 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/06 17:17:14 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <math.h>
#include "mxw.h"

int	__copy_pixel(t_mxw_image *cut_image, t_mxw_fip_param *param);

/**
 * @brief cut image.
 * @param param parameter structure ref. details.
 * @return new cut image in memory. NULL if an error occur or
 *         is not setted parameter.
*/
t_mxw_image	*mxw_cut_image(t_mxw_cut_image_param *param)
{
	t_mxw_image	*cut_image;

	cut_image = mxw_new_image(param->mxw,
			param->image->width, param->image->height);
	if (cut_image == NULL)
		return (NULL);
	mxw_foreach_image((t_mxw_foreach_image_param []){{
		.image = param->image,
		.f = __copy_pixel,
		.height = param->height,
		.width = param->width,
		.offset_x = param->x,
		.offset_y = param->y,
		.result = NULL,
		.your_param = cut_image,
	}});
	return (cut_image);
}

int	__copy_pixel(t_mxw_image *cut_image, t_mxw_fip_param *param)
{
	int	color;

	color = mxw_pixel_get_from_image(
			param->image, param->image_x, param->image_y);
	mxw_pixel_put_to_image(cut_image, param->index_x, param->index_y, color);
	return (0);
}
