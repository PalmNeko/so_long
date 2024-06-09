/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_xpm_file_to_image_test.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:15:41 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/09 17:01:41 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mxw.h"
#include "mxw_test.h"

const char	*test_case_name = "mxw_xpm_file_to_image";

int	inner_test_setup(t_test_this *this)
{
	t_mxw_image	*image;
	image = mxw_xpm_file_to_image(this->mxw, "assets/textures.xpm");
	if (image == NULL)
		return (-1);
	mxw_put_image_to_window(this->win, image, 0, 0);
	mxw_destroy_image(image);
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
