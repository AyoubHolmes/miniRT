/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initializer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 13:49:43 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/12/23 11:36:10 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_objects		*ligth_initializer(char **lp, char **lc, char *brightness)
{
	t_light		*light;
	t_objects	*obj;

	if (!(light = (t_light*)malloc(sizeof(t_light))))
		return (0);
	if (!(obj = (t_objects*)malloc(sizeof(t_objects))))
		return (0);
	light->light_pos = initialize_vector(ft_atof(lp[0]), ft_atof(lp[1]), ft_atof(lp[2]));
	light->light_color = initialize_vector(ft_atof(lc[0]), \
						ft_atof(lc[1]), ft_atof(lc[2]));
	light->brightness = ft_atof(brightness);
	obj->id = 3;
	obj->content = light;
	obj->next = NULL;
	return (obj);
}

t_objects		*cam_initializer(char **vp, char **cn, char *fov)
{
	t_cam_data	*cam;
	t_objects	*obj;

	if (!(cam = (t_cam_data*)malloc(sizeof(t_cam_data))))
		return (0);
	if (!(obj = (t_objects*)malloc(sizeof(t_objects))))
		return (0);
	cam->view_point = initialize_vector(ft_atof(vp[0]), ft_atof(vp[1]), ft_atof(vp[2]));
	cam->cam_normal = initialize_vector(ft_atof(cn[0]), ft_atof(cn[1]), ft_atof(cn[2]));
	cam->cam_normal.x += 0.0001;
	cam->fov = ft_atof(fov);
	obj->id = 2;
	obj->content = cam;
	obj->next = NULL;
	return (obj);
}
