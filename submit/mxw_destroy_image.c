/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_destroy_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:36:32 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/08 13:00:31 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "mxw.h"

void	mxw_destroy_image(t_mxw_image *img)
{
	if (img == NULL)
		return ;
	mlx_destroy_image(img->mxw->mlx, img->img);
	free(img);
}
