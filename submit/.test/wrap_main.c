/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 04:39:08 by marvin            #+#    #+#             */
/*   Updated: 2024/06/21 04:39:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "cident.h"

int	__real_main(int argc, char *argv[]);

int	__wrap_main(int argc, char *argv[])
{
	char	*error_count_down_str;
	int		error_count_down;

	if (getenv("IS_DEBUG") != NULL)
		cident_set_debug(true);
	error_count_down = 0;
	error_count_down_str = getenv("ERROR_COUNT_DOWN");
	error_count_down = ft_atoi(error_count_down_str);
	if (error_count_down > 0)
		cident_set_error(error_count_down);
	return (__real_main(argc, argv));
}
