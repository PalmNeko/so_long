/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_foreach_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:49:50 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/08 15:13:33 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mxw_param.h"
#include "libft.h"
#include <math.h>

/**
 * @brief for each image data.
 * @attention Loops that exceed the width and height of the image are ignored.
 * f = int (*f)(void *your_param, t_mxw_fip_param *iterate_param)
 */
void	*mxw_foreach_image(t_mxw_foreach_image_param *param)
{
	int	x;
	int	y;
	int	end_y;
	int	end_x;
	int	start_x;

	y = (int)ft_ifl(param->offset_y < 0, -1 * param->offset_y, 0);
	start_x = (int)ft_ifl(param->offset_x < 0, -1 * param->offset_x, 0);
	end_y = (int)ft_ifl(param->offset_y + param->height > param->image->height,
			param->image->height, param->offset_y + param->height);
	end_x = (int)ft_ifl(param->offset_x + param->width > param->image->width,
			param->image->width, param->offset_x + param->width);
	while (y + param->offset_y < end_y)
	{
		x = start_x;
		while (x + param->offset_x < end_x)
			param->f(param->your_param, (t_mxw_fip_param []){{
					.image = param->image, .image_x = x + param->offset_x,
					.image_y = y + param->offset_y, .index_x = x, .index_y = y,
					.result = param->result}}), x++;
		y++;
	}
	return (param->result);
}
