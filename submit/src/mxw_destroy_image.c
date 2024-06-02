/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_destroy_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:36:32 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/02 19:10:16 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "mxw.h"

int	mxw_destroy_image(t_mxw *mxw, t_mxw_image *img)
{
	int	result;
	result = mlx_destroy_image(mxw->mlx, img->img);
	free(img);
	return (result);
}
