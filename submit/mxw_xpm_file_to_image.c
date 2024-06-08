/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_xpm_file_to_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:58:15 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/08 16:45:23 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <mlx.h>
#include "mxw_int.h"

t_mxw_image	*mxw_xpm_file_to_image(t_mxw *mxw, char *filename)
{
	t_mxw_image	*image;
	void		*mlx_img;
	int			width;
	int			height;

	mlx_img = mlx_xpm_file_to_image(mxw->mlx, filename, &width, &height);
	if (mlx_img == NULL)
		return (NULL);
	image = mxw_generate_from_mlx_image(mxw, mlx_img, width, height);
	if (image == NULL)
		return (mlx_destroy_image(mxw->mlx, mlx_img), NULL);
	return (image);
}
