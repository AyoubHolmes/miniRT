/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_trs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:33:20 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/12/01 14:42:59 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			rotate(t_data *d, char **data)
{
	t_vector	rotvec;
	char		**values;

	values = ft_split(data[1], ',');
	rotvec = (t_vector){atof(values[0]), atof(values[1]),
	atof(values[2])};
	if (d->last_obj->id == 2)
		((t_cam_data*)d->last_obj->content)->cam_normal = rotatevect(
		((t_cam_data*)d->last_obj->content)->cam_normal, rotvec);
	else if (d->last_obj->id == 5)
		((t_plane*)d->last_obj->content)->plane_norm = rotatevect(
		((t_plane*)d->last_obj->content)->plane_norm, rotvec);
	else if (d->last_obj->id == 6)
		((t_square*)d->last_obj->content)->square_norm = rotatevect(
		((t_square*)d->last_obj->content)->square_norm, rotvec);
	else if (d->last_obj->id == 7)
		((t_cylinder*)d->last_obj->content)->cylinder_norm = rotatevect(
		((t_cylinder*)d->last_obj->content)->cylinder_norm, rotvec);
}

t_vector		transvect(t_vector torot, t_vector rotvec)
{
	torot.x = torot.x + rotvec.x;
	torot.y = torot.y + rotvec.y;
	torot.z = torot.z + rotvec.z;
	return (torot);
}

void			translate(t_data *d, char **data)
{
	t_vector	tvec;
	char		**values;

	values = ft_split(data[1], ',');
	tvec = (t_vector){atof(values[0]), atof(values[1]),
	atof(values[2])};
	if (d->last_obj->id == 2)
		((t_cam_data*)d->last_obj->content)->view_point = transvect(
		((t_cam_data*)d->last_obj->content)->view_point, tvec);
	else if (d->last_obj->id == 5)
		((t_plane*)d->last_obj->content)->plane_center = transvect(
		((t_plane*)d->last_obj->content)->plane_center, tvec);
	else if (d->last_obj->id == 6)
		((t_square*)d->last_obj->content)->square_center = transvect(
		((t_square*)d->last_obj->content)->square_center, tvec);
	else if (d->last_obj->id == 7)
		((t_cylinder*)d->last_obj->content)->cylinder_center = transvect(
		((t_cylinder*)d->last_obj->content)->cylinder_center, tvec);
}
