/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_destroy_mxw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:50:10 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/07 23:26:29 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mxw_int.h"
#include "libft.h"

void	mxw_destroy_mxw(t_mxw *mxw)
{
	mxw_int_clean_windows(mxw);
	free(mxw);
	return ;
}
