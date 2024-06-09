/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_cut_image_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:15:41 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/09 12:40:52 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mxw.h"
#include "mxw_test.h"

const char	*test_case_name = "mxw_cut_image_test";

int	inner_test_setup(t_test_this *this)
{
	t_mxw_image	*texture;
	t_mxw_image	*cutted_image;

	texture = mxw_xpm_file_to_image(this->mxw, "../submit/textures/textures.xpm");
	if (texture == NULL)
		return (-1);
	cutted_image = mxw_cut_image((t_mxw_cut_image_param []) {{
		.mxw = this->mxw,
		.image = texture,
		.x = 0 + 16 * 10,
		.y = 0 + 16 * 10,
		.height = 16 * 1,
		.width = 16 * 31,}});
	if (cutted_image == NULL)
		return (mxw_destroy_image(texture), -1);
	mxw_put_image_to_window(this->win, cutted_image, 0, 0);
	mxw_destroy_image(texture);
	mxw_destroy_image(cutted_image);
	mxw_flip_screen(this->win);
	return (0);
}

int	inner_test_loop(t_test_this *this)
{
	(void)this;
	return (0);
}

int	inner_test_destroy(t_test_this *this)
{
	(void)this;
	return (0);
}
