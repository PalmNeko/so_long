/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_calc_alpha_blend.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:54:45 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/09 18:20:55 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mxw.h"

int _calc_alpha_blend(int base_color, int overlap_color, int (*f)());

int	mxw_calc_alpha_blend(int base_color, int overlap_color)
{
	int new_r;
	int new_g;
	int new_b;
	int	new_t;

	new_r = _calc_alpha_blend(base_color, overlap_color, mxw_get_color_r);
	new_g = _calc_alpha_blend(base_color, overlap_color, mxw_get_color_g);
	new_b = _calc_alpha_blend(base_color, overlap_color, mxw_get_color_b);
	new_t = 0;
	return (mxw_create_trgb(new_t, new_r, new_g, new_b));
}

int _calc_alpha_blend(int base_color, int overlap_color, int (*f)())
{
	double	alpha;
	int	base_alpha;
	int overlap_alpha;

	base_alpha = (255 - mxw_get_color_t(base_color));
	overlap_alpha = (255 - mxw_get_color_t(overlap_color));
	if (base_alpha == 0)
		alpha = 1;
	else
		alpha = overlap_alpha / base_alpha;
	return (f(base_color) * (1 - alpha) + f(overlap_color) * alpha);
}
