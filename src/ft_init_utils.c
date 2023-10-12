// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_init_utils.c                                    :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/10/08 15:49:56 by tkilling          #+#    #+#             */
// /*   Updated: 2023/10/12 14:54:27 by snagulap         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "miniRT.h"

// double	ft_atodouble(char *str, int *i)
// {
// 	double	nbr;
// 	int		minus;
// 	double	pow;

// 	nbr = 0.0;
// 	pow = 1;
// 	minus = 1;
// 	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == ',')
// 		(*i)++;
// 	while (str[*i] == '-' || str[*i] == '+')
// 	{
// 		if (str[(*i)++] == '-')
// 			minus = -1;
// 	}
// 	while (ft_isdigit(str[*i]))
// 	{
// 		nbr = nbr * 10.0;
// 		nbr = nbr + str[(*i)++] - 48.0;◊
// 	}
// 	if (str[(*i)++] != '.')
// 		return (nbr * minus);
// 	while (ft_isdigit(str[*i]))
// 	{
// 		pow = pow * 0.1;
// 		nbr = nbr + ((str[(*i)++] - 48) * pow);
// 	}
// 	return (nbr * minus);
// }

// int	ft_line_error_message(int line)
// {
// 	char	*nbr;

// 	write(2, "Error\ntype identifier in line: ", 32);
// 	nbr = ft_itoa(line);
// 	write(2, nbr, ft_strlen(nbr));
// 	free(nbr);
// 	write(2, "\n", 1);
// 	return (1);
// }

// int	ft_check_color_range(t_rgb *color)
// {
// 	if (color->red > 255 || color->red < 0)
// 		return(1);
// 	if (color->green > 255 || color->green < 0)
// 		return(1);
// 	if (color->blue > 255 || color->blue < 0)
// 		return(1);
// 	return (0);
// }
// /*
// int	ft_check_normalized_vector_range(t_vec3 *xyz)
// {
// 	if (xyz->x > 1 || xyz->x < -1)
// 		return (1);
// 	if (xyz->y > 1 || xyz->y < -1)
// 		return (1);
// 	if (xyz->z > 1 || xyz->z < -1)
// 		return (1);
// 	return (0);
// }
// */