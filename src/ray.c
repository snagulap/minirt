/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:02:38 by snagulap          #+#    #+#             */
/*   Updated: 2023/10/06 13:19:43 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_ray	make_ray(t_coordinates origin, t_vec3 direction)
{
	t_ray	r;

	r.orig = origin;
	r.dir = direction;
	return (r);
}

t_coordinates	ray_origin(const t_ray *r)
{
	return (r->orig);
}

t_vec3	ray_direction(const t_ray *r)
{
	return (r->dir);
}

t_coordinates	ray_at(const t_ray *r, double t)
{
	return (vec3_add(ray_origin(r), vec3_multiply(ray_direction(r), t)));
}
