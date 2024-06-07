/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 01:25:40 by marvin            #+#    #+#             */
/*   Updated: 2024/06/07 22:49:54 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "mxw.h"
#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	t_sl_this	ls_this;
	int			result;

	result = mxw_start(sl_setup, sl_loop, &ls_this, &ls_this);
	if (result != 0)
		return (1);
	return (0);
}

__attribute__((destructor))
void	destructor(void)
{
	int		status;
	char	buf[50];

	printf("%s\n", "leak check now...");
	snprintf(buf, 50, "leaks %d &> leaksout", getpid());
	status = system(buf);
	if (status)
	{
		write(2, "leak!!!\n", 8);
		system("cat leaksout >/dev/stderr");
		exit(1);
	}
}
