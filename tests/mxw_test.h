/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mxw_test.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:16:35 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/08 15:38:09 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MXW_TEST_H
# define MXW_TEST_H

#include "mxw_types.h"

typedef struct	s_test_this {
	t_mxw_window	*win;
	t_mxw			*mxw;
	void			*extend_args;
}	t_test_this;

int	test_leaks(char *label);
int	inner_test_setup(t_test_this *this);
int	inner_test_loop(t_test_this *this);
int	inner_test_destroy(t_test_this *this);

#endif
