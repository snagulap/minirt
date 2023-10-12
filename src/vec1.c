/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:20:22 by snagulap          #+#    #+#             */
/*   Updated: 2023/10/09 14:20:45 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
