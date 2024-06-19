/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_resize_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:36:36 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/10 18:36:36 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mxw.h"

int	put_pixel_for_resize(t_mxw_image *new_image, t_mxw_fip_param *param);

t_mxw_image	*mxw_resize_image(
	t_mxw *mxw, t_mxw_image *base_image, int width, int height)
{
	t_mxw_image	*new_image;

	new_image = mxw_new_image(mxw, width, height);
	if (new_image == NULL)
		return (NULL);
	mxw_foreach_image((t_mxw_foreach_image_param []){{
		.f = put_pixel_for_resize,
		.height = new_image->height,
		.image = new_image,
		.offset_x = 0,
		.offset_y = 0,
		.result = NULL,
		.width = new_image->width,
		.your_param = base_image}});
	return (new_image);
}

int	put_pixel_for_resize(t_mxw_image *base_image, t_mxw_fip_param *param)
{
	int	x;
	int	y;
	int	color;

	x = param->index_x * base_image->width / param->image->width;
	y = param->index_y * base_image->height / param->image->height;
	color = mxw_pixel_get_from_image(base_image, x, y);
	mxw_pixel_put_to_image(param->image, param->index_x, param->index_y, color);
	return (0);
}
