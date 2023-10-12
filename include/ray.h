/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:48:54 by snagulap          #+#    #+#             */
/*   Updated: 2023/10/10 21:24:47 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

typedef struct s_vec
{
	double	e[3];
}			t_vec3;

// typedef struct s_coordinates
// {
// 	double	x;
// 	double	y;
// 	double	z;
// }			t_coordinates;

typedef struct s_ray
{
	t_vec3	orig;
	t_vec3	dir;
}			t_ray;

t_vec3		make_vec3(double e0, double e1, double e2);
t_vec3		vec3_negate(t_vec3 v);
double		vec3_get(const t_vec3 *v, int i);
void		vec3_set(t_vec3 *v, int i, double value);
t_vec3		vec3_add(t_vec3 u, t_vec3 v);
t_vec3		vec3_sub(t_vec3 u, t_vec3 v);
t_vec3		vec3_multiply(t_vec3 u, t_vec3 v);
t_vec3		vec3_scalar_multiply(t_vec3 v, double t);
t_vec3		vec3_scalar_divide(t_vec3 v, double t);
t_vec3		vec3_scalar_add(t_vec3 v, double t);
double		vec3_dot(t_vec3 u, t_vec3 v);
t_vec3		vec3_cross(t_vec3 u, t_vec3 v);
double		vec3_length(t_vec3 v);
double		vec3_length_squared(t_vec3 v);
t_vec3		vec3_normalize(t_vec3 v);
t_ray		make_ray(t_vec3 origin, t_vec3 direction);
t_vec3		ray_origin(const t_ray r);
t_vec3		ray_direction(const t_ray r);
t_vec3		ray_at(const t_ray r, double t);

#endif