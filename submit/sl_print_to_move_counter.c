/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_print_to_move_counter.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 18:02:37 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/15 18:02:37 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sl_conf.h"

#ifdef PRINT_MOVE_COUNTER_TO_SHELL

void	sl_print_move_counter(int move_count)
{
	ft_putnbr_fd(move_count, 1);
	ft_putstr_fd("\n", 1);
	return ;
}

#endif

#ifndef PRINT_MOVE_COUNTER_TO_SHELL

void	sl_print_move_counter(int move_count)
{
	(void)move_count;
	return ;
}

#endif
