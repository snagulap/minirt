/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:02:38 by snagulap          #+#    #+#             */
/*   Updated: 2023/10/08 17:56:33 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_ray	make_ray(t_vec3 origin, t_vec3 direction)
{
	t_ray	r;

	r.orig = origin;
	r.dir = direction;
	return (r);
}

t_vec3	ray_origin(const t_ray r)
{
	return (r.orig);
}

t_vec3	ray_direction(const t_ray r)
{
	return (r.dir);
}

t_vec3	ray_at(const t_ray r, double t)
{
	t_vec3	scaled_direction;

	scaled_direction = vec3_scalar_multiply(r.dir, t);
	return (vec3_add(ray_origin(r), scaled_direction));
}
