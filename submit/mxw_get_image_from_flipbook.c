/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_get_image_from_flipbook.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 21:40:44 by marvin            #+#    #+#             */
/*   Updated: 2024/06/06 21:40:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mxw_types.h"

t_mxw_image	*mxw_get_image_from_flipbook(t_mxw_flipbook *flipbook)
{
	return (flipbook->flip_book[flipbook->iter]);
}
