/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:33:25 by snagulap          #+#    #+#             */
/*   Updated: 2023/11/02 17:25:41 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// Modify the function definitions as follows:
t_color	make_color(double red, double green, double blue)
{
	t_color	color;

	color.red = red;
	color.green = green;
	color.blue = blue;
	return (color);
}
t_rgb	make_color_rgb(double red, double green, double blue)
{
	t_rgb	color;

	color.red = red;
	color.green = green;
	color.blue = blue;
	return (color);
}

t_color	calculateAmbientLight(const t_ambient_lightning *ambient,
		const t_rgb *baseColor)
{
	t_color	ambientColor;
	double	r;
	double	g;
	double	b;

	r = (ambient->color.red / 255.0) * ambient->am_ratio;
	g = (ambient->color.green / 255.0) * ambient->am_ratio;
	b = (ambient->color.blue / 255.0) * ambient->am_ratio;
	ambientColor.red = r;
	ambientColor.green = g;
	ambientColor.blue = b;
	// Apply ambient light to the base color
	ambientColor.red *= baseColor->red;
	ambientColor.green *= baseColor->green;
	ambientColor.blue *= baseColor->blue;
	return (ambientColor);
}

t_color	calculateLighting(const t_light *light, const t_vec3 *point,
		const t_vec3 *normal)
{
	t_color	lighting;
	t_vec3	lightDirection;
	double	diffuseFactor;

	// Calculate the direction from the point to the light source
	lightDirection = vec3_normalize(vec3_sub(make_vec3(light->light_point.e[0],
					light->light_point.e[1], light->light_point.e[2]), *point));
	// Calculate the diffuse reflection (Lambertian reflection)
	diffuseFactor = vec3_dot(lightDirection, *normal);
	if (diffuseFactor < 0.0)
		diffuseFactor = 0.0;
	// Calculate the lighting color
	lighting.red = light->color.red * light->brightness * diffuseFactor;
	lighting.green = light->color.green * light->brightness * diffuseFactor;
	lighting.blue = light->color.blue * light->brightness * diffuseFactor;
	return (lighting);
}

t_color	rayColor(t_ray *ray, t_sphere	*sphere)
{
	
	double				t;
	t_vec3				normal;
	t_color				color;
	t_ambient_lightning	ambient;
	t_color				ambientColor;
	t_light				light;
	t_color				lighting;
	t_ambient_lightning	am;

	// sphere.center = make_vec3(0, 0, 20.6);
	// sphere.radius = 12.6;
	// sphere.rgb_colors = make_color_rgb(0.0, 0.0, 255);
	// ambient = (t_ambient_lightning){0.2, make_color(255, 255, 255)};
	ambient.am_ratio = 0.2;
    ambient.color = make_color(255, 255, 255);
	if (hitSphere(sphere, ray, &t))
	{
		// normal = vec3_normalize(vec3_sub(ray->orig, sphere.center));
		// Calculate the ambient lighting
		ambientColor = calculateAmbientLight(&ambient, &sphere->rgb_colors);
		// Define the light structure
		// light = (t_light){{-40.0, 50.0, 0.0}, 0.6, make_color(10, 0, 255)};
		light.light_point = make_vec3(-40.0, 50.0, 0.0);
        light.brightness = 0.6;
        light.color = make_color(10, 0, 255);
		// Calculate the diffuse lighting from the light source
		lighting = calculateLighting(&light, &sphere->center, &normal);
		// Combine ambient and diffuse lighting
		// color = vec3_add(ambientColor, lighting);
		// Combine ambient and diffuse lighting
        color.red = ambientColor.red + lighting.red;
        color.green = ambientColor.green + lighting.green;
        color.blue = ambientColor.blue + lighting.blue;
		return (color);
	}
	// Background color
	am.am_ratio = 0.2;
	am.color = make_color(am.am_ratio * 255, am.am_ratio * 255, am.am_ratio
			* 255);
	// Calculate the background color using ambient light
	color = calculateAmbientLight(&am, &sphere->rgb_colors);
	return (color);
}

/*
t_color	rayColor(t_ray *ray)
{
	t_sphere	sphere;
	double		t;
	t_vec3		normal;
	t_color		color;
	// t_color		white_color;
	// t_color		blue_color;
	t_color		interpolated_color;
	t_vec3		unit_direction;
	double		a;
    t_plane     plane;
	t_ambient_lightning ambient;

    plane.pointC = make_vec3(0.0, 0.0, -10.0);
    plane.normalV = make_vec3(0.0, 1.0, 0.0);
	sphere.center = (t_vec3){0, 0, 20.6,};
	sphere.radius =  12.6;
	sphere.rgb_colors = (t_rgb){0.0, 0.0, 255};
	ambient = (t_ambient_lightning){0.2, {255, 255,255}};
	if (hitSphere(&sphere, ray, &t))
    // if(hitPlane(ray, &plane, &t, &normal))
	{
		normal.e[0] = ray->orig.e[0] + t * ray->dir.e[0] - sphere.center.e[0];
		normal.e[1] = ray->orig.e[1] + t * ray->dir.e[1] - sphere.center.e[1];
		normal.e[2] = ray->orig.e[2] + t * ray->dir.e[2] - sphere.center.e[2];
		// normal = vec3_normalize(normal);
		normal = vec3_scalar_add(normal, 1.0);
		color = vec3_scalar_multiply(normal, 0.5);
		// color = calculateAmbientLight(&ambient, sphere.rgb_colors);

		return (color);
	}
	// Background color
	t_ambient_lightning am;
	am.am_ratio = 0.2;
	am.color.red = am.am_ratio * 255;

	unit_direction = vec3_normalize(ray->dir);
	a = 0.5 * (unit_direction.e[1] + 1.0);
	// white_color = make_vec3(1.0, 1.0, 1.0);
	// blue_color = make_vec3(0.5, 0.7, 1.0);
	// interpolated_color.e[0] = (1.0 - a) * white_color.e[0] + a
	// 	* blue_color.e[0];
	// interpolated_color.e[1] = (1.0 - a) * white_color.e[1] + a
	// 	* blue_color.e[1];
	// interpolated_color.e[2] = (1.0 - a) * white_color.e[2] + a
	// 	* blue_color.e[2];
    // interpolated_color.e[0] = (1.0 - a) * white_color.e[0] + a
	// * color.e[0];
    // interpolated_color.e[1] = (1.0 - a) * white_color.e[1] + a
	// * color.e[1];
    // interpolated_color.e[2] = (1.0 - a) * white_color.e[2] + a
	// * color.e[2];
	interpolated_color = vec3_add(
        vec3_scalar_multiply(make_vec3(1.0, 1.0, 1.0), (1.0 - a)),
        vec3_scalar_multiply(make_vec3(0.5, 0.7, 1.0), a)
    );
	return (interpolated_color);
}*/
