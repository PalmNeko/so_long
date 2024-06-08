/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .template_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:15:41 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/08 15:48:33 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mxw.h"
#include "mxw_test.h"

const char	*test_case_name = "template";

int	inner_test_setup(t_test_this *this)
{
	mxw_set_end(this->mxw);
	return (0);
}

int	inner_test_loop(t_test_this *this)
{
	return (0);
}

int	inner_test_destroy(t_test_this *this)
{
	return (0);
}
