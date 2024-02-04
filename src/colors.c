/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:33:25 by snagulap          #+#    #+#             */
/*   Updated: 2024/02/04 12:32:56 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// Modify the function definitions as follows:
t_vec3	make_color(double red, double green, double blue)
{
	t_vec3	color;

	color.e[0] = red;
	color.e[1] = green;
	color.e[2] = blue;
	return (color);
}
// t_rgb	make_color_rgb(double red, double green, double blue)
// {
// 	t_rgb	color;

// 	color.red = red;
// 	color.green = green;
// 	color.blue = blue;
// 	return (color);
// }

t_vec3	calculateAmbientLight(t_ambient_lightning *ambient, t_vec3 *baseColor)
{
	t_vec3	ambientColor;
	double	r, g, b;

	r = (ambient->color.e[0] / 255.0) * ambient->am_ratio;
	g = (ambient->color.e[1] / 255.0) * ambient->am_ratio;
	b = (ambient->color.e[2] / 255.0) * ambient->am_ratio;
	ambientColor.e[0] = r;
	ambientColor.e[1] = g;
	ambientColor.e[2] = b;
	// Apply ambient light to the base color
	ambientColor.e[0] *= baseColor->e[0];
	ambientColor.e[1] *= baseColor->e[1];
	ambientColor.e[2] *= baseColor->e[2];
	return (ambientColor);
}

t_vec3	calculateLighting(const t_light *light, t_hit_record  *rec, t_obj* object)
{
	t_vec3	lighting;
	t_vec3	lightDirection;
	double	diffuseFactor;
	t_ray	shadow;
	
	t_ambient_lightning ambient = {.am_ratio= 0.2, .color = {255, 255, 255}};
	// Calculate the direction from the point to the light source
	// rec->normal = vec3_add(rec[0].p, rec->normal);
	lightDirection = vec3_normalize(vec3_sub(light->light_point, rec[0].p));
	shadow = (t_ray){rec[0].p, lightDirection};
	diffuseFactor = vec3_dot(lightDirection, rec[0].p);
	diffuseFactor = fmin(fmax(0.0, diffuseFactor),1);
	printf(" %d \n", hit_sphere(&shadow, 0.0001, INFINITY, &rec[1], object));
	if(hit_sphere(&shadow, 0.0001, INFINITY, &rec[1], object)
		&& (vec3_length(vec3_sub(light->light_point, shadow.orig)))
		> rec[1].t)
		diffuseFactor = 0;
	lighting = vec3_scalar_multiply(light->color, diffuseFactor * light->brightness);
	lighting = vec3_add(lighting,vec3_scalar_multiply(ambient.color, ambient.am_ratio));
	lighting = calculateAmbientLight(&ambient, &lighting);
	lighting = vec3_multiply(lighting, rec->color);
	// printf("%.f %.f %.f \n", lighting.e[0],lighting.e[1],lighting.e[2]);
	return (lighting);
}


t_vec3	rayColor(t_ray *ray, t_obj* object)
{
	float		a;
	t_vec3		final_color;
	t_hit_record	hit_record[2];
	// t_vec3		unit_direction;
	// t_vec3		light_direction;
	// t_ray		shadow_ray;
		
	t_light light = {.light_point={-40.0,50.0,0.0}, .brightness=0.6, .color={10,0,255}};
	if (hit_sphere(ray, 0.001f, INFINITY, &hit_record[0], object))
	{
		// light_direction = vec3_normalize(vec3_sub(light.light_point, hit_record[0].p));
		// shadow_ray = (t_ray){hit_record[0].p, light_direction};
		// a = fmin(fmax(vec3_dot(hit_record[0].normal, light_direction), 0), 1);

		// if (hit_sphere(&shadow_ray, .001f, INFINITY, &hit_record[1], object)
		// 	&& vec3_length(vec3_sub(light.light_point, shadow_ray.orig))
		// 		> hit_record[1].t)
		// 	a = 0;

		// light_color = vec3_scalar_multiply(light.color, a * light.brightness);
		// light_color = vec3_add((t_vec3)light_color,
		// 		vec3_scalar_multiply(ambient.color,ambient.am_ratio));
		// final_color = vec3_multiply(light_color, hit_record[0].color);
			final_color = calculateLighting(&light, &hit_record[0], object);
			// printf("%.f %.f %.f \n", final_color.e[0],final_color.e[1],final_color.e[2]);
		return final_color;
	}
	// unit_direction = vec3_normalize(ray->dir);
	a = 0.5 * (vec3_normalize(ray->dir).e[1] + 1.0);
	final_color = vec3_add(vec3_scalar_multiply((t_vec3){1, 1, 1}, 1.0 - a),
		vec3_scalar_multiply((t_vec3){0.5, 0.7, 1.0}, a));
	// printf("%.f %.f %.f \n", final_color.e[0],final_color.e[1],final_color.e[2]);
	return final_color;
}
	// double				t;
	// t_vec3				normal;
	// t_ambient_lightning	ambient;
	// t_color				ambientColor;
	// t_light				light;
	// t_color				lighting;
	// // t_ambient_lightning	am;
	// if	(hit_sphere(ray,0.01f,INFINITY,rec,object))
    // {
	// 	// normal.e[0] = ray->orig.e[0] + t * ray->dir.e[0] - sphere.center.e[0];
	// 	// normal.e[1] = ray->orig.e[1] + t * ray->dir.e[1] - sphere.center.e[1];
	// 	// normal.e[2] = ray->orig.e[2] + t * ray->dir.e[2] - sphere.center.e[2];
	// 	// normal = vec3_normalize(normal);
	// 	normal = vec3_normalize(vec3_sub(light.light_point,rec->p));
	// 	color = vec3_scalar_multiply(normal, 0.5);
	// 	// color = calculateAmbientLight(&ambient, sphere.rgb_colors);

	// 	return (color);
	// }



	// ambient = (t_ambient_lightning){0.2, make_color(255, 255, 255)};
	// if(hit_sphere(ray,0.01f,INFINITY,rec,object))
	// {
	// 	// Calculate the ambient lighting
	// 	// ambientColor = calculateAmbientLight(&ambient, &sphere->rgb_colors);
	// 	// Define the light structure
	// 	// light = (t_light){{-40.0, 50.0, 0.0}, 0.6, make_color(10, 0, 255)};
	// 	light.light_point = make_vec3(0.0, 0, 30);
    //     light.brightness = 0.7;
    //     light.color = make_color(255, 255, 255);
	// 	normal = vec3_normalize(vec3_sub(ray->orig, sphere->center));
	// 	// Calculate the diffuse lighting from the light source
	// 	lighting = calculateLighting(&light, &sphere->center, &normal);
	// 	// lighting = calculateLighting(&light, &ray->orig, &normal);
	// 	// Combine ambient and diffuse lighting
	// 	// color = vec3_add(ambientColor, lighting);
	// 	// Combine ambient and diffuse lighting
    //     color.red = ambientColor.red + lighting.red;
    //     color.green = ambientColor.green + lighting.green;
    //     color.blue = ambientColor.blue + lighting.blue;
	// 	return (color);
	// }
	// // Background color
	// // am.am_ratio = 0.2;
	// t_ambient_lightning am = {.am_ratio = 0.2, .color = {.red = 51, .green = 51, .blue = 51}};
	// am.color = make_color(am.am_ratio * 255, am.am_ratio * 255, am.am_ratio
	// 		* 255);
	// // Calculate the background color using ambient light
	// color = calculateAmbientLight(&am, &sphere->rgb_colors);
	// return (color);


// t_color rayColor(const t_ray *ray, const t_plane *plane) {
//     double t;
//     t_vec3 normal;
//     t_color color;
//     t_ambient_lightning ambient = {0.2, make_color(255, 255, 255)};
//     t_light light = {make_vec3(0.0, 0, 30), 0.7, make_color(255, 255, 255)};

//     if (hitPlane(ray, plane, &t, &normal)) {
//         t_color ambientColor = calculateAmbientLight(&ambient, &plane->rgb_colors);
//         normal = vec3_normalize(normal);
//         t_color lighting = calculateLighting(&light, &plane->pointC, &normal);

//         color.red = ambientColor.red + lighting.red;
//         color.green = ambientColor.green + lighting.green;
//         color.blue = ambientColor.blue + lighting.blue;

//         return color;
//     }

//     t_ambient_lightning am = {.am_ratio = 0.2, .color = {.red = 51, .green = 51, .blue = 51}};
//     am.color = make_color(am.am_ratio * 255, am.am_ratio * 255, am.am_ratio * 255);

//     color = calculateAmbientLight(&am, &plane->rgb_colors);
//     return color;
// }

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
	static t_vec3	r_color(t_ray r, t_scene *scene)
{
	float		weight;
	t_ray		s_ray;
	t_vec3		l_dir;
	t_vec3		l_col;
	t_record	rec[2];

	if (hit(r, (float []){.001f, 1.f / 0.f}, &rec[0], scene))
	{
		l_dir = vec3_normalize(vec3_elem_op(scene->light.pos, '-', rec[0].p));
		s_ray = (t_ray){rec[0].p, l_dir};
		weight = fmin(fmax(vec3_dot(rec[0].n, l_dir), 0), 1);
		if (hit(s_ray, (float []){.001f, 1.f / 0.f}, &rec[1], scene)
			&& vec3_length(vec3_elem_op(scene->light.pos, '-', s_ray.ori))
				> rec[1].t)
			weight = 0;
		l_col = vec3_scale(weight * scene->light.param[3], scene->light.color);
		l_col = vec3_elem_op(l_col, '+',
				vec3_scale(scene->ambient.param[3], scene->ambient.color));
		return (vec3_elem_op(l_col, '*', rec[0].c));
	}
	weight = .5f * (vec3_normalize(r.dir).y + 1.f);
	return (vec3_elem_op(vec3_scale(1.f - weight, (t_vec3){1, 1, 1}), '+',
		vec3_scale(weight, (t_vec3){.5f, .7f, 1.f})));
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
