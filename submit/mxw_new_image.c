/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_new_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:19:20 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/02 18:00:16 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "mxw_types.h"
#include "mxw_int.h"

t_mxw_image	*mxw_new_image(t_mxw *mxw, int width, int height)
{
	t_mxw_image	*image;
	void		*mlx_img;

	mlx_img = mlx_new_image(mxw->mlx, width, height);
	if (mlx_img == NULL)
		return (NULL);
	image = mxw_generate_from_mlx_image(mlx_img, width, height);
	if (image == NULL)
		return (mlx_destroy_image(mxw->mlx, mlx_img), NULL);
	return (image);
}
