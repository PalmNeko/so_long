/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_put_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 05:30:36 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/16 05:30:36 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"
#include "libft.h"

void	sl_put_error(int sl_errno)
{
	char	*errtext;

	ft_putstr_fd("Error\n", 2);
	errtext = sl_strerror(sl_errno);
	if (errtext != NULL)
	{
		ft_putstr_fd(errtext, 2);
		ft_putstr_fd("\n", 2);
	}
	return ;
}
