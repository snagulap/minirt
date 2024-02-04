/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:31:42 by snagulap          #+#    #+#             */
/*   Updated: 2024/02/04 16:03:41 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// int	solveQuadratic(double a, double b, double c, double *root1, double *root2)
// {
// 	double	discriminant;
// 	double	sqrtDiscriminant;

// 	discriminant = b * b - 4 * a * c;
// 	if (discriminant < 0)
// 		// No real roots
// 		return (0);
// 	else if (discriminant == 0)
// 	{
// 		// One real root
// 		*root1 = -b / (2 * a);
// 		return (1);
// 	}
// 	else
// 	{
// 		// Two real roots
// 		sqrtDiscriminant = sqrt(discriminant);
// 		*root1 = (-b + sqrtDiscriminant) / (2 * a);
// 		*root2 = (-b - sqrtDiscriminant) / (2 * a);
// 		return (2);
// 	}
// }


// int	hitSphere(const t_sphere *sphere, const t_ray *ray, double *t)
// {
// 	t_vec3	oc;
// 	double	a;
// 	double	b;
// 	double	c;
// 	int		num_roots;

// 	oc = vec3_sub(ray->orig, sphere->center);
// 	a = vec3_dot(ray->dir, ray->dir);
// 	b = 2.0 * vec3_dot(oc, ray->dir);
// 	c = vec3_dot(oc, oc) - (sphere->radius / 2.0) * (sphere->radius / 2.0);
// 	double root1, root2;
// 	num_roots = solveQuadratic(a, b, c, &root1, &root2);
// 	if (num_roots == 0)
// 		return (0);
// 	else if (num_roots == 1)
// 	{
// 		if (root1 > 0)
// 		{
// 			*t = root1;
// 			return (1);
// 		}
// 		return (0);
// 	}
// 	else
// 	{
// 		if (root1 > 0 && root2 > 0)
// 		{
// 			*t = fmin(root1, root2);
// 			return (1);
// 		}
// 		else if (root1 > 0)
// 		{
// 			*t = root1;
// 			return (1);
// 		}
// 		else if (root2 > 0)
// 		{
// 			*t = root2;
// 			return (1);
// 		}
// 		return (0);
// 	}
// }

// int hit(hittable world, ray r, double t_min, double t_max, double *t, vec3 *normal) {
//     int hit_anything = 0;
//     double closest_so_far = t_max;

//     for (int i = 0; i < world.size; ++i) {
//         sphere s = world.spheres[i];
//         if (hit_sphere(s, r, t_min, closest_so_far, t, normal)) {
//             hit_anything = 1;
//             closest_so_far = *t;
//         }
//     }
//     return hit_anything;
// }

 bool hit_sphere(const t_ray* r, double tmin, double tmax, t_hit_record* rec, t_obj *objt)
 {
	t_vec3 oc = vec3_sub(r->orig, objt->cor);	
	double a = vec3_length(r->dir);
	double b = vec3_dot(oc, r->dir);
	double c = vec3_dot(oc, oc) - (objt->rad * objt->rad);
	// if (c > 0 && b > 0)
	// 	return (0);
	double discriminant = b * b - a * c;
	float sqrtd = sqrt(discriminant);
	float t = (-b - sqrtd) / a; 
	// if (t <= tmin)
    if (t <= tmin || tmax <= t)
    {	
	    t = (-b + sqrt(discriminant)) / a;
		if (t <= tmin || tmax <= t )	
            return 0;
	}
	// float t = (-b - sqrtd) / a ; 
	// if (t <= tmin || tmax <= t)
		
	// 	return (0);	
	rec->t = t;
	rec->p = vec3_add(r->orig, vec3_scalar_multiply(r->dir, t));
	// t_vec3 onormal = vec3_scalar_multiply(vec3_sub(rec->p, objt->cor), 1.0f / objt->rad);
	// rec->normal = 
	rec->normal = vec3_scalar_multiply(vec3_add(objt->cor, vec3_scalar_multiply(r->dir, t)), 1.0f / objt->rad);
	// rec->normal = vec3_scalar_multiply(vec3_sub(rec->p, objt->cor), 1.0f / objt->rad);
	rec->color = vec3_scalar_multiply(objt->rgb,1.0f / 255.0f);
	return (1);
 }

// int hitSphere(const t_sphere *sphere, const t_ray *ray, double *t, t_vec3 *normal) {
//     t_vec3 oc = vec3_sub(ray->orig, sphere->center);
//     // double a = vec3_dot(ray->dir, ray->dir);
//     double b = vec3_dot(oc, ray->dir);
//     double c = vec3_dot(oc, oc) - (sphere->radius * sphere->radius);

//     double discriminant = b * b - c;
    
// 	if (discriminant < 0)
// 		return (0);
//     double temp = (-b - sqrt(discriminant));	
// 	// printf("%.02f", discriminant);
//     if (discriminant < 0) {
//         // printf("%.2f", temp);
//         if (temp > 0) {
//             *t = temp;
//             *normal = vec3_normalize(vec3_sub(vec3_add(ray->orig, vec3_scalar_multiply(ray->dir, *t)), sphere->center));
//             return 1;
//         }

//         temp = (-b + sqrt(discriminant));
//         // printf("%.2f", temp);
//         if (temp > 0) {
//             *t = temp;
//             *normal = vec3_normalize(vec3_sub(vec3_add(ray->orig, vec3_scalar_multiply(ray->dir, *t)), sphere->center));
//             return 1;
//         }
//     }

//     return 1;
// }


// Function to calculate the intersection between a ray and a plane
int	hitPlane(const t_ray *ray, t_plane *plane, double *t, t_vec3 *normal)
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
