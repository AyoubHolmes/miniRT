/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 19:04:19 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/12/22 19:04:49 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		key_press(int keycode, t_main *m)
{
	if (keycode == 53 || keycode == 12)
	{
		free_list(m->d.lights);
		free_list(m->d.obj);
		exit(0);
	}
	if (keycode == 123)
	{
		m->d.cameras = get_cam_previous(&m->d.cameras);
		graphic_drawer(m);
	}
	if (keycode == 124)
	{
		m->d.cameras = get_cam_next(&m->d.cameras);
		graphic_drawer(m);
	}
	return (0);
}
