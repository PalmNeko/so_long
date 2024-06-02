/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 00:11:00 by marvin            #+#    #+#             */
/*   Updated: 2024/06/02 00:11:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILITY_H
# define MLX_UTILITY_H

# include "mlx_utility_types.h"

int				create_trgb(unsigned char t,
					unsigned char r, unsigned char g, unsigned char b);
unsigned char	get_t(int trgb);
unsigned char	get_r(int trgb);
unsigned char	get_g(int trgb);
unsigned char	get_b(int trgb);
void			my_mlx_pixel_put(t_img_infos *data, int x, int y, int color);

#endif