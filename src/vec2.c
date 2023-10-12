/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:23:49 by snagulap          #+#    #+#             */
/*   Updated: 2023/10/09 15:50:06 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
