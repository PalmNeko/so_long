/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:15:51 by tookuyam          #+#    #+#             */
/*   Updated: 2024/06/08 16:42:23 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mxw.h"
#include "mxw_test.h"

extern char *test_case_name;

int	test_window_destroy(t_test_this *this)
{
	mxw_set_end(this->mxw);
	return (0);
}

int	keyboard_handler(int keycode, t_test_this *this)
{
	if (keycode == KEY_ESC)
		mxw_set_end(this->mxw);
	return (0);
}

int test_setup(t_mxw *mxw, t_test_this	*this)
{

	this->mxw = mxw;
	this->extend_args = NULL;
	this->win = mxw_new_window(mxw, 1920, 1080, test_case_name);
	inner_test_setup(this);
	mxw_add_event(this->win, ON_DESTROY, test_window_destroy, this);
	mxw_add_event(this->win, ON_KEYDOWN, keyboard_handler, this);
	return (0);
}

int test_loop(t_mxw *mxw, t_test_this	*this)
{
	inner_test_loop(this);
	return (0);
	(void)mxw;
}

int test_destroy(t_mxw *mxw, t_test_this	*this)
{
	inner_test_destroy(this);
	test_leaks(test_case_name);
	return (0);
	(void)mxw;
}

int	main(void)
{
	int					result;
	t_test_this			this;
	t_mxw_start_param	mxw_start_param;

	mxw_start_param = (t_mxw_start_param){
		.setup = test_setup,
		.loop = test_loop,
		.destroy = test_destroy,
		.setup_args = &this,
		.loop_args = &this,
		.destroy_args = &this};
	result = mxw_start(mxw_start_param);
	if (result != 0)
		return (0);
	return (0);
}
