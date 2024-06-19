/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_calc_alpha_blend.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:54:45 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/19 16:26:46 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mxw.h"

/**
 * @brief alpha blend
 * @note this function many is called. I write for speed.
 */
int	mxw_calc_alpha_blend(int base_color, int fore_color)
{
	double	alpha;
	int		base_alpha;
	int		fore_alpha;
	int		fore_t;

	fore_t = mxw_get_color_t(fore_color);
	if (fore_t == 0)
		return (fore_color);
	else if (fore_t == 255)
		return (base_color);
	base_alpha = (255 - mxw_get_color_t(base_color));
	fore_alpha = (255 - mxw_get_color_t(fore_color));
	alpha = fore_alpha / base_alpha;
	return (mxw_create_trgb(
			0,
			mxw_get_color_r(base_color) * (1 - alpha)
			+ mxw_get_color_r(fore_color) * alpha,
			mxw_get_color_g(base_color) * (1 - alpha)
			+ mxw_get_color_g(fore_color) * alpha,
			mxw_get_color_b(base_color) * (1 - alpha)
			+ mxw_get_color_b(fore_color) * alpha));
}
