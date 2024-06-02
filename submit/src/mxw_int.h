/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_int.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:59:02 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/02 18:03:33 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MXW_INT_H
# define MXW_INT_H

#include "mxw_types.h"

t_mxw_image	*mxw_generate_from_mlx_image(void *mlx_img, int width, int height);
void		mxw_destroy_mxw(t_mxw *mxw);

#endif
