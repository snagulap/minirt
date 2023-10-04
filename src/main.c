/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:14:55 by snagulap          #+#    #+#             */
/*   Updated: 2023/10/04 14:41:40 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 400

#define RED_PIXEL 0xFF0000

typedef vec3 color;

void pix_color(color pixel_color)
{
	v2.e[0] = (int)(255.999 * pixel_color.e[0]),
	v2.e[1] = (int)(255.999 * pixel_color.e[1]),
    v2.e[2] = (int)(255.999 * pixel_color.e[2]);
}
void	render(void *mlx, void *window, t_rgb *rgb)
{
	int	color;
	int	j;
	int	i;
	
	for (j = 0; j < WINDOW_HEIGHT; ++j)
	{
		for (i = 0; i < WINDOW_WIDTH; ++i)
		{
			rgb->red = (double)i / (WINDOW_WIDTH - 1);
			rgb->green = (double)j / (WINDOW_HEIGHT - 1);
			rgb->blue = 0;
			rgb->red = (int)(255.999 * rgb->red);
			rgb->green = (int)(255.999 * rgb->green);
			rgb->blue = (int)(255.999 * rgb->blue);
			color = ((int)rgb->red << 16) | ((int)rgb->green << 8) |
				(int)rgb->blue;
			mlx_pixel_put(mlx, window, i, j, color);
		}
	}
}

int	main	(int argc, char** argv)
{
	// t_minirt	*rt;
	t_rgb		*rgb;
	// int			color;
	void		*mlx;
	void		*window;
	color pixel_color = {0.5, 0.7, 1.0};
	rgb = malloc(sizeof(struct t_rgb *));
	if (rgb == NULL)
		return (1);
	mlx = mlx_init();
	if (!mlx)
		return (1);
	argc = 0;
	argv = 0;
	window = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "My Window");
	if (!window)
		return (1);
	// color = (rgb->blue << 16) | (rgb->green << 8) | rgb->red;
	render(mlx, window, rgb);
	vec3 v1 = make_vec3(1.0, 2.0, 3.0);
    vec3 v2 = make_vec3(3.0, 2.0, 1.0);

    printf("v1: %f %f %f\n", v1.e[0], v1.e[1], v1.e[2]);
    printf("v2: %f %f %f\n", v2.e[0], v2.e[1], v2.e[2]);

    vec3 sum = vec3_add(v1, v2);
    printf("Sum: %f %f %f\n", sum.e[0], sum.e[1], sum.e[2]);

    double dot_product = vec3_dot(v1, v2);
    printf("Dot Product: %f\n", dot_product);

    vec3 cross_product = vec3_cross(v1, v2);
    printf("Cross Product: %f %f %f\n", cross_product.e[0], cross_product.e[1], cross_product.e[2]);

    vec3 normalized = vec3_normalize(v1);
    printf("Normalized v1: %f %f %f\n", normalized.e[0], normalized.e[1], normalized.e[2]);
	mlx_loop(mlx);
	free(rgb);
	mlx_destroy_window(mlx, window);
	return (0);
}
