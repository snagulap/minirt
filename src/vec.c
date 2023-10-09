/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:21:10 by snagulap          #+#    #+#             */
/*   Updated: 2023/10/09 12:41:23 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// Function to create a vec3 with specified components
t_vec3	make_vec3(double e0, double e1, double e2)
{
	t_vec3	v;

	v.e[0] = e0;
	v.e[1] = e1;
	v.e[2] = e2;
	return (v);
}

// Function to negate a vec3
t_vec3	vec3_negate(t_vec3 v)
{
	return (make_vec3(-v.e[0], -v.e[1], -v.e[2]));
}

// Function to access a component of a vec3
double	vec3_get(const t_vec3 *v, int i)
{
	return (v->e[i]);
}

// Function to set a component of a vec3
void	vec3_set(t_vec3 *v, int i, double value)
{
	v->e[i] = value;
}

// Function to add two vec3 vectors
t_vec3	vec3_add(t_vec3 u, t_vec3 v)
{
	return (make_vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]));
}

t_vec3	vec3_scalar_add(t_vec3 v, double value)
{
	return (make_vec3(v.e[0] + value, v.e[1] + value, v.e[2] + value));
}

t_vec3	vec3_sub(t_vec3 u, t_vec3 v)
{
	return (make_vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]));
}

// Function to multiply two vec3 vectors element-wise
t_vec3	vec3_multiply(t_vec3 u, t_vec3 v)
{
	return (make_vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]));
}

// Function to multiply a vec3 by a scalar
t_vec3	vec3_scalar_multiply(t_vec3 v, double t)
{
	return (make_vec3(t * v.e[0], t * v.e[1], t * v.e[2]));
}

// Function to divide a vec3 by a scalar
t_vec3	vec3_scalar_divide(t_vec3 v, double t)
{
	return (make_vec3(v.e[0] * (1 / t), v.e[1] * (1 / t), v.e[2] * (1 / t)));
}

// Function to compute the dot product of two vec3 vectors
double	vec3_dot(t_vec3 u, t_vec3 v)
{
	return (u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2]);
}

// Function to compute the cross product of two vec3 vectors
t_vec3	vec3_cross(t_vec3 u, t_vec3 v)
{
	return (make_vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1], u.e[2] * v.e[0]
			- u.e[0] * v.e[2], u.e[0] * v.e[1] - u.e[1] * v.e[0]));
}

// Function to compute the length of a vec3 vector
double	vec3_length(t_vec3 v)
{
	return (sqrt(v.e[0] * v.e[0] + v.e[1] * v.e[1] + v.e[2] * v.e[2]));
}

// Function to compute the squared length of a vec3 vector
double	vec3_length_squared(t_vec3 v)
{
	return (v.e[0] * v.e[0] + v.e[1] * v.e[1] + v.e[2] * v.e[2]);
}

// Function to normalize a vec3 vector
t_vec3	vec3_normalize(t_vec3 v)
{
	double	length;

	length = vec3_length(v);
	return (vec3_scalar_divide(v, length));
}
