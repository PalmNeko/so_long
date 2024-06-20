/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_xpm_file_to_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:58:15 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/21 03:42:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <mlx.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "mxw_int.h"

/**
 * The mlx_xpm_file_to_image function returns a value without any problem even
 * if it fails to close the file. However, since I wanted to return NULL when
 * close failed, special error handling was performed. at: mlx_img
 */
t_mxw_image	*mxw_xpm_file_to_image(t_mxw *mxw, char *filename)
{
	t_mxw_image	*image;
	void		*mlx_img;
	int			width;
	int			height;

	errno = 0;
	mlx_img = mlx_xpm_file_to_image(mxw->mlx, filename, &width, &height);
	if (mlx_img == NULL)
		return (NULL);
	else if (errno != 0 && errno != EAGAIN)
		return (mlx_destroy_image(mxw->mlx, mlx_img), NULL);
	image = mxw_generate_from_mlx_image(mxw, mlx_img, width, height);
	if (image == NULL)
		return (mlx_destroy_image(mxw->mlx, mlx_img), NULL);
	return (image);
}
