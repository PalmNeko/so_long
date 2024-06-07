/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_flip_flipbbok.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 21:36:02 by marvin            #+#    #+#             */
/*   Updated: 2024/06/06 21:36:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mxw_types.h"

int	mxw_flip_flipbbook(t_mxw_flipbook *flipbook, int cnt)
{
	flipbook->iter += cnt;
	flipbook->iter %= flipbook->size;
	flipbook->iter += flipbook->size;
	flipbook->iter %= flipbook->size;
	return (0);
}
