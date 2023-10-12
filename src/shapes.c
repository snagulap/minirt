/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:31:42 by snagulap          #+#    #+#             */
/*   Updated: 2023/10/12 19:20:37 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	solveQuadratic(double a, double b, double c, double *root1, double *root2)
{
	double	discriminant;
	double	sqrtDiscriminant;

	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
	{
		// No real roots
		return (0);
	}
	else if (discriminant == 0)
	{
		// One real root
		*root1 = -b / (2 * a);
		return (1);
	}
	else
	{
		// Two real roots
		sqrtDiscriminant = sqrt(discriminant);
		*root1 = (-b + sqrtDiscriminant) / (2 * a);
		*root2 = (-b - sqrtDiscriminant) / (2 * a);
		return (2);
	}
}

int	hitSphere(const t_sphere *sphere, const t_ray *ray, double *t)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	int		num_roots;

	oc = vec3_sub(ray->orig, sphere->center);
	printf("%f %f %f\n", oc.e[0], oc.e[1], oc.e[2]);
	printf("%f %f %f\n", ray->dir.e[0], ray->dir.e[1], ray->dir.e[2]);
	a = vec3_dot(ray->dir, ray->dir);
	printf("a:::%f\n", a);
	b = 2.0 * vec3_dot(oc, ray->dir);
	printf("b:::%f\n", b);
	c = vec3_dot(oc, oc) - (sphere->radius / 2.0) * (sphere->radius / 2.0);
	printf("c:::%f\n", a);
	double root1, root2;
	num_roots = solveQuadratic(a, b, c, &root1, &root2);
	if (num_roots == 0)
	{
		return (0);
	}
	else if (num_roots == 1)
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


// Function to calculate the intersection between a ray and a plane
int	hitPlane(const t_ray *ray, const t_plane *plane, double *t, t_vec3 *normal)
{
	double	dDotV;
	t_vec3	pcMinusP;
	double	xDotV;

	// Calculate D|V
	dDotV = ray->dir.e[0] * plane->normalV.e[0] + ray->dir.e[1]
		* plane->normalV.e[1] + ray->dir.e[2] * plane->normalV.e[2];
	// Check if D|V is close to zero (considering a small epsilon value)
	if (fabs(dDotV) < 1e-6)
	{
		// Ray is nearly parallel to the plane, no intersection
		return (0);
	}
	// Calculate X|V
	pcMinusP = make_vec3(plane->pointC.e[0] - ray->orig.e[0], plane->pointC.e[1]
		- ray->orig.e[1], plane->pointC.e[2] - ray->orig.e[2]);
	xDotV = pcMinusP.e[0] * plane->normalV.e[0] + pcMinusP.e[1] * plane->normalV.e[1]
		+ pcMinusP.e[2] * plane->normalV.e[2];
	// Calculate t
	*t = -xDotV / dDotV;
	// Check if t is negative (behind the ray's origin)
	if (*t < 0)
	{
		return (0);
	}
	// Calculate the surface normal vector N
	if (dDotV < 0)
	{
		// D|V is negative, set N to -V
		normal->e[0] = -plane->normalV.e[0];
		normal->e[1] = -plane->normalV.e[1];
		normal->e[2] = -plane->normalV.e[2];
	}
	else
	{
		// D|V is positive, set N to V
		normal->e[0] = plane->normalV.e[0];
		normal->e[1] = plane->normalV.e[1];
		normal->e[2] = plane->normalV.e[2];
	}
	return (1);
}