/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:21:10 by snagulap          #+#    #+#             */
/*   Updated: 2023/10/09 14:23:40 by snagulap         ###   ########.fr       */
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
