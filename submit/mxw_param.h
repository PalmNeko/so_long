/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_param.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 22:42:01 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/07 23:04:47 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MXW_PARAM_H
# define MXW_PARAM_H

# include "mxw_types.h"

typedef struct s_mxw_start_param	t_mxw_start_param;

/**
 * will call bellow:
 * 	setup(mxw, setup_args);
 * 	loop(mxw, loop_args);
 * 	destroy(destroy_args);
*/
struct s_mxw_start_param {
	int		(*setup)();
	int		(*loop)();
	int		(*destroy)();
	void	*setup_args;
	void	*loop_args;
	void	*destroy_args;
};

typedef struct s_mxw_cut_image_param {
	t_mxw		*mxw;
	t_mxw_image	*image;
	int			x;
	int			y;
	int			width;
	int			height;
}	t_mxw_cut_image_param;

/**
 * @param image iterate image.
 * @param your_param you want to use param.
 * @param f your each function
 * 			int (*f)(void *your_param, t_mxw_fip_param *param)
 * @param offset_x start pixel point of image.
 * @param offset_y start pixel point of image.
 * @param width	loop width
 * @param height loop height
 * @param result The data here is passed to each loop and set
 * 	as the last return value.
*/
typedef struct s_mxw_foreach_image_param {
	t_mxw_image	*image;
	void		*your_param;
	int			(*f)();
	int			offset_x;
	int			offset_y;
	int			width;
	int			height;
	void		*result;
}	t_mxw_foreach_image_param;

/**
 * @param image_x image point
 * @param image_y image point
 * @param index_x index point
 * @param index_y index point
 * @param image image data
 * @param result please store your calculate result.
*/
typedef struct s_mxw_fip_param {
	int			image_x;
	int			image_y;
	int			index_x;
	int			index_y;
	t_mxw_image	*image;
	void		*result;
}	t_mxw_fip_param;

#endif
