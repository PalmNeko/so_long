/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_new_body.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 21:50:39 by marvin            #+#    #+#             */
/*   Updated: 2024/06/06 21:50:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mxw.h"

t_mxw_body	*mxw_new_body(t_mxw *mxw, t_mxw_flipbook *flipbook)
{
	t_mxw_body	*new_body;

	new_body = (t_mxw_body *)malloc(sizeof(t_mxw_body));
	if (new_body == NULL)
		return (NULL);
	new_body->x = 0;
	new_body->y = 0;
	new_body->flipbook = mxw_clone_flipbook(mxw, flipbook);
	return (new_body);
}
