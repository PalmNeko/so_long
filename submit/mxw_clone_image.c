/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_clone_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 21:19:33 by marvin            #+#    #+#             */
/*   Updated: 2024/06/06 21:19:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "mxw.h"

t_mxw_image	*mxw_clone_image(t_mxw *mxw, t_mxw_image *image)
{
	t_mxw_image	*cloned_image;
	int			x;
	int			y;
	int			color;

	cloned_image = mxw_new_image(mxw, image->width, image->height);
	if (cloned_image == NULL)
		return (NULL);
	y = 0;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			color = mxw_pixel_get_from_image(image, x, y);
			mxw_pixel_put_to_image(cloned_image, x, y, color);
			x++;
		}
		y++;
	}
	return (cloned_image);
}
