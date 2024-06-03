/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_generate_from_mlx_image.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:59:58 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/02 19:11:00 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "mxw_types.h"

t_mxw_image	*mxw_generate_from_mlx_image(void *mlx_img, int width, int height)
{
	t_mxw_image	*image;

	image = (t_mxw_image *)malloc(sizeof(t_mxw_image));
	if (image == NULL)
		return (NULL);
	image->img = mlx_img;
	image->addr = mlx_get_data_addr(image->img,
			&image->bits_per_pixel, &image->line_length, &image->endian);
	if (image->addr == NULL)
		return (free(image), NULL);
	image->width = width;
	image->height = height;
	return (image);
}
