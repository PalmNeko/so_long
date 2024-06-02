/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 02:13:52 by marvin            #+#    #+#             */
/*   Updated: 2024/06/02 02:13:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utility_types.h"

void	my_mlx_pixel_put(t_img_infos *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
