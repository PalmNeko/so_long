/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_destroy_flipbook.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 21:32:27 by marvin            #+#    #+#             */
/*   Updated: 2024/06/06 21:32:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mxw.h"

void	mxw_destroy_flipbook(t_mxw_flipbook *flipbook)
{
	int	index;

	index = 0;
	while (index < flipbook->size)
	{
		mxw_destroy_image(flipbook->flip_book[index]);
		index++;
	}
	free(flipbook);
	return ;
}
