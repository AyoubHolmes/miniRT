/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:19:29 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/12/01 14:19:32 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector add(t_vector v1, t_vector v2)
{
	t_vector v3;
	v3.x = v1.x + v2.x;
	v3.y = v1.y + v2.y;
	v3.z = v1.z + v2.z;
	return (v3);
}

t_vector minus(t_vector v1, t_vector v2)
{
	t_vector v3;
	v3.x = v1.x - v2.x;
	v3.y = v1.y - v2.y;
	v3.z = v1.z - v2.z;
	return (v3);
}

t_vector substract(t_vector v1, t_vector v2)
{
	t_vector v3;
	v3.x = v1.x - v2.x;
	v3.y = v1.y - v2.y;
	v3.z = v1.z - v2.z;
	return (v3);
}

t_vector multiple(double t, t_vector v)
{
	t_vector v3;
	v3.x = t * v.x;
	v3.y = t * v.y;
	v3.z = t * v.z;
	return (v3);
}

double  scalar(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}