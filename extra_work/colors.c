/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:46:55 by snagulap          #+#    #+#             */
/*   Updated: 2023/10/26 22:47:43 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// t_color calculateAmbientLight(const t_ambient_lightning *ambient,
	// const t_color *baseColor) {
//     t_color ambientColor;

//     double r = (ambient->color.red / 255.0) * ambient->am_ratio;
//     double g = (ambient->color.green / 255.0) * ambient->am_ratio;
//     double b = (ambient->color.blue / 255.0) * ambient->am_ratio;

//     ambientColor = make_vec3(r, g, b);

//     // Apply ambient light to the base color
//     ambientColor = vec3_multiply(ambientColor, *baseColor);
// 		 return (ambientColor);
// }

// t_color calculateLighting(const t_light *light, const t_vec3 *point,
	// const t_vec3 *normal)
// {
//     t_color lighting;

//     // Calculate the direction from the point to the light source
//     t_vec3 lightDirection = vec3_normalize(vec3_sub(make_vec3(light->light_point.e[0],
				// light->light_point.e[1], light->light_point.e[2]), *point));

//     // Calculate the diffuse reflection (Lambertian reflection)
//     double diffuseFactor = vec3_dot(lightDirection, *normal);
//     if (diffuseFactor < 0.0) {
//         diffuseFactor = 0.0;
//     }

//     // Calculate the lighting color
//     lighting = vec3_scalar_multiply(light->color, light->brightness
		// * diffuseFactor);

//     return (lighting);
// }