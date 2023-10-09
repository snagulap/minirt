/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:11:35 by snagulap          #+#    #+#             */
/*   Updated: 2023/10/09 12:25:59 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// int	hitSphere(const t_Sphere *sphere, const t_ray *ray, double *t)
// {
// 	t_vec3	oc;
// 	double	a;
// 	double	b;
// 	double	c;
// 	int		numRoots;

// 	oc.e[0] = ray->orig.e[0] - sphere->center.e[0];
// 	oc.e[1] = ray->orig.e[1] - sphere->center.e[1];
// 	oc.e[2] = ray->orig.e[2] - sphere->center.e[2];
// 	a = ray->dir.e[0] * ray->dir.e[0] + ray->dir.e[1] * ray->dir.e[1]
// 		+ ray->dir.e[2] * ray->dir.e[2];
// 	b = 2 * (oc.e[0] * ray->dir.e[0] + oc.e[1] * ray->dir.e[1] + oc.e[2]
// 			* ray->dir.e[2]);
// 	c = oc.e[0] * oc.e[0] + oc.e[1] * oc.e[1] + oc.e[2] * oc.e[2]
// 		- sphere->radius * sphere->radius;
// 	double root1, root2;
// 	numRoots = solveQuadratic(a, b, c, &root1, &root2);
// 	if (numRoots == 0)
// 	{
// 		return (0); // No intersection
// 	}
// 	else if (numRoots == 1)
// 	{
// 		if (root1 > 0)
// 		{
// 			*t = root1;
// 			return (1); // One intersection point in front of ray
// 		}
// 		return (0); // Intersection point behind ray
// 	}
// 	else
// 	{
// 		if (root1 > 0 && root2 > 0)
// 		{
// 			*t = fmin(root1, root2);
// 			return (1); // Two intersection points, take the nearest
// 		}
// 		else if (root1 > 0)
// 		{
// 			*t = root1;
// 			return (1); // One intersection point in front of ray
// 		}
// 		else if (root2 > 0)
// 		{
// 			*t = root2;
// 			return (1); // One intersection point in front of ray
// 		}
// 		return (0); // Both intersection points behind ray
// 	}
// }

// t_color	rayColor(const t_ray *ray)
// {
// 	t_Sphere	sphere;
// 	double		t;
// 	t_vec3		normal;
// 	// double		len;
// 	t_color		color;
// 	t_color		white_color;
// 	t_color		blue_color;
// 	t_color		interpolated_color;
// 	t_vec3		unit_direction;
// 	double		a;

// 	sphere.center.e[0] = 0;
// 	sphere.center.e[1] = 0;
// 	sphere.center.e[2] = -1;
// 	sphere.radius = 0.5;
// 	if (hitSphere(&sphere, ray, &t))
// 	{
// 		normal.e[0] = ray->orig.e[0] + t * ray->dir.e[0] - sphere.center.e[0];
// 		normal.e[1] = ray->orig.e[1] + t * ray->dir.e[1] - sphere.center.e[1];
// 		normal.e[2] = ray->orig.e[2] + t * ray->dir.e[2] - sphere.center.e[2];
// 		vec3_normalize(normal);
// 		// len = sqrt(normal.e[0] * normal.e[0] + normal.e[1] * normal.e[1]
// 		// 		+ normal.e[2] * normal.e[2]);
// 		// normal.e[0] /= len;
// 		// normal.e[1] /= len;
// 		// normal.e[2] /= len;
// 		color.e[0] = 0.5 * (normal.e[0] + 1.0);
// 		color.e[1] = 0.5 * (normal.e[1] + 1.0);
// 		color.e[2] = 0.5 * (normal.e[2] + 1.0);
// 		return (color);
// 	}
// 	// Background color
// 	unit_direction = vec3_normalize(ray->dir);
// 	a = 0.5 * (unit_direction.e[1] + 1.0);
// 	white_color = make_vec3(1.0, 1.0, 1.0);
// 	blue_color = make_vec3(0.5, 0.7, 1.0);
// 	interpolated_color.e[0] = (1.0 - a) * white_color.e[0] + a
// 		* blue_color.e[0];
// 	interpolated_color.e[1] = (1.0 - a) * white_color.e[1] + a
// 		* blue_color.e[1];
// 	interpolated_color.e[2] = (1.0 - a) * white_color.e[2] + a
// 		* blue_color.e[2];
// 	return (interpolated_color);
// }