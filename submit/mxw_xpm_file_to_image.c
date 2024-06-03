/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_xpm_file_to_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:58:15 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/02 19:16:12 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <mlx.h>
#include "mxw_int.h"


t_mxw_image	*mxw_xpm_file_to_image(t_mxw *mxw, char *filename, int *width, int *height)
{
	t_mxw_image	*image;
	void		*mlx_img;

	mlx_img = mlx_xpm_file_to_image(mxw->mlx, filename, width, height);
	if (mlx_img == NULL)
		return (NULL);
	image = mxw_generate_from_mlx_image(mlx_img, *width, *height);
	if (image == NULL)
		return (mlx_destroy_image(mxw->mlx, mlx_img), NULL);
	return (image);
}
