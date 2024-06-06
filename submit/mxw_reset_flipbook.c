/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_reset_flipbook.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 21:41:49 by marvin            #+#    #+#             */
/*   Updated: 2024/06/06 21:41:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mxw_types.h"

void	mxw_reset_flipbook(t_mxw_flipbook *flipbook)
{
	flipbook->iter = 0;
	return ;
}
