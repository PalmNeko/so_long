/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_print_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 20:41:56 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/06 16:17:45 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mxw_types.h"

int	mxw_print_image(t_mxw_image *image)
{
	printf("img: %p\n", image->img);
	printf("addr: %p\n", image->addr);
	printf("endian: %d\n", image->endian);
	printf("bits_per_pixel: %d\n", image->bits_per_pixel);
	printf("line_length: %d\n", image->line_length);
	printf("width: %d\n", image->width);
	printf("height: %d\n", image->height);
	return (0);
}
