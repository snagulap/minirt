/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:31:42 by snagulap          #+#    #+#             */
/*   Updated: 2023/10/09 13:32:42 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	hitSphere(const t_sphere *sphere, const t_ray *ray, double *t)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	int		numRoots;

	oc = vec3_sub(ray->orig, sphere->center);
	a = vec3_dot(ray->dir, ray->dir);
	b = 2.0 * vec3_dot(oc, ray->dir);
	c = vec3_dot(oc, oc) - sphere->radius * sphere->radius;
	double root1, root2;
	numRoots = solveQuadratic(a, b, c, &root1, &root2);
	if (numRoots == 0)
	{
		return (0);
	}
	else if (numRoots == 1)
	{
		if (root1 > 0)
		{
			*t = root1;
			return (1);
		}
		return (0);
	}
	else
	{
		if (root1 > 0 && root2 > 0)
		{
			*t = fmin(root1, root2);
			return (1);
		}
		else if (root1 > 0)
		{
			*t = root1;
			return (1);
		}
		else if (root2 > 0)
		{
			*t = root2;
			return (1);
		}
		return (0);
	}
}
