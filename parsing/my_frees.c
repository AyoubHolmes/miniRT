/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_frees.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulbaz <aboulbaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:46:49 by aboulbaz          #+#    #+#             */
/*   Updated: 2020/12/01 11:05:20 by aboulbaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			free_list(t_objects *list)
{
	t_objects	*p;
	t_objects	*q;

	p = list;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		my_free_main(q);
	}
}

void			my_free_main(void *t)
{
	if (t)
	{
		free(t);
		t = NULL;
	}
}
