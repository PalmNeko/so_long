/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_clone_flipbook.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:06:01 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/07 12:08:30 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mxw.h"

t_mxw_flipbook	*mxw_clone_flipbook(t_mxw *mxw, t_mxw_flipbook *flipbook)
{
	t_mxw_flipbook	*cloned;

	cloned = mxw_new_flipbook(mxw, flipbook->flip_book, flipbook->size);
	if (cloned == NULL)
		return (NULL);
	return (cloned);
}
