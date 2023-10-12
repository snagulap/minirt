/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:33:25 by snagulap          #+#    #+#             */
/*   Updated: 2023/10/10 15:05:42 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_rgb make_color(double red, double green, double blue)
{
    t_rgb color;
    color.red = red;
    color.green = green;
    color.blue = blue;
    return (color);
}

t_color	rayColor(const t_ray *ray)
{
	t_sphere	sphere;
	double		t;
	t_vec3		normal;
	t_color		color;
	t_color		white_color;
	// t_color		blue_color;
	t_color		interpolated_color;
	t_vec3		unit_direction;
	double		a;
    t_plane     plane;
    
    plane.pointC = make_vec3(0.0, 0.0, -10.0);
    plane.normalV = make_vec3(0.0, 1.0, 0.0);
	sphere.center.e[0] = 0;
	sphere.center.e[1] = 0;
	sphere.center.e[2] = 20.6;
	sphere.radius = 12.6;
    
	if (hitSphere(&sphere, ray, &t))
    // if(hitPlane(ray, &plane, &t, &normal))
	{
		normal.e[0] = ray->orig.e[0] + t * ray->dir.e[0] - sphere.center.e[0];
		normal.e[1] = ray->orig.e[1] + t * ray->dir.e[1] - sphere.center.e[1];
		normal.e[2] = ray->orig.e[2] + t * ray->dir.e[2] - sphere.center.e[2];
		normal = vec3_normalize(normal);
		// normal = vec3_scalar_add(normal, 1.0);
		// color = vec3_scalar_multiply(normal, 0.5);
		// color = 

		return (normal);
	}
	// Background color
	unit_direction = vec3_normalize(ray->dir);
	a = 0.5 * (unit_direction.e[1] + 1.0);
	white_color = make_vec3(1.0, 1.0, 1.0);
	// blue_color = make_vec3(0.0, 0.0, 0.0);
	// interpolated_color.e[0] = (1.0 - a) * white_color.e[0] + a
	// 	* blue_color.e[0];
	// interpolated_color.e[1] = (1.0 - a) * white_color.e[1] + a
	// 	* blue_color.e[1];
	// interpolated_color.e[2] = (1.0 - a) * white_color.e[2] + a
	// 	* blue_color.e[2];
    interpolated_color.e[0] = (1.0 - a) * white_color.e[0] + a * color.e[0];
    interpolated_color.e[1] = (1.0 - a) * white_color.e[1] + a * color.e[1];
    interpolated_color.e[2] = (1.0 - a) * white_color.e[2] + a * color.e[2];
	return (interpolated_color);
}
