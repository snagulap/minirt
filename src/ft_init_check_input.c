/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_check_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:59:23 by tkilling          #+#    #+#             */
/*   Updated: 2023/10/12 14:57:49 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// int	ft_check_file(miniRT *data, int fd);
// int	ft_check_line(miniRT *data, char *str, int i);

// int	ft_check_A(miniRT *data, char *str, int i);
// int	ft_check_C(miniRT *data, char *str, int i);
// int	ft_check_L(miniRT *data, char *str, int i);
// int	ft_check_sp(miniRT *data, char *str, int i);
// int	ft_check_pl(miniRT *data, char *str, int i);
// int	ft_check_cy(miniRT *data, char *str, int i);

// int	ft_check_file(miniRT *data, int fd)
// {
// 	char	*str;
// 	int		line;
// 	int		i;

// 	str = get_next_line(fd);
// 	line = 1;
// 	while (str)
// 	{
// 		i = 0;
// 		while (i < 1000 && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
// 			i++;
// 		if (str[i] != '\0' && ft_check_line(data, str, i))
// 		{
// 			return (ft_line_error_message(line));
// 		}
// 		free(str);
// 		str = get_next_line(fd);
// 		line++;
// 	}
// 	return (0);
// }

// int	ft_check_line(miniRT *data, char *str, int i)
// {
// 	if (str[i] == 'A' && (str[i + 1] == ' ' || str[i + 1] == '\t'))
// 	{
// 		return (ft_check_A(data, str, i + 1));
// 	}
// 	else if (str[i] == 'C' && (str[i + 1] == ' ' || str[i + 1] == '\t'))
// 	{
// 		return (ft_check_C(data, str, i + 1));
// 	}
// 	else if (str[i] == 'L' && (str[i + 1] == ' ' || str[i + 1] == '\t'))
// 	{
// 		return (ft_check_L(data, str, i + 1));
// 	}
// 	else if (str[i] == 's' && str[i + 1] == 'p' && (str[i + 2] == ' ' || str[i
// 			+ 2] == '\t'))
// 	{
// 		return (ft_check_sp(data, str, i + 2));
// 	}
// 	else if (str[i] == 'p' && str[i + 1] == 'l' && (str[i + 2] == ' ' || str[i
// 			+ 2] == '\t'))
// 	{
// 		return (ft_check_pl(data, str, i + 2));
// 	}
// 	else if (str[i] == 'c' && str[i + 1] == 'y' && (str[i + 2] == ' ' || str[i
// 			+ 2] == '\t'))
// 	{
// 		return (ft_check_cy(data, str, i + 2));
// 	}
// 	else
// 		return (1);
// 	return (0);
// }
/*
int	ft_check_float(char *str, int i);
int	ft_check_one(char *str, int *i);
int	ft_check_three(char *str, int *i);

int	ft_check_A(miniRT *data, char *str, int i)
{
	if (++(data->nbr_amb_lightning) != 1)
		return (1);
	if (ft_check_one(str, &i))
		return (1);
	if (str[i] != ' ' && str[i] != '\t')
		return (1);
	if (ft_check_three(str, &i))
		return (1);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] != '\0' && str[i] != '\n')
		return (1);
	return (0);
}

int	ft_check_C(miniRT *data, char *str, int i)
{
	if (++(data->nbr_camera) != 1)
		return (1);
	if (ft_check_three(str, &i))
		return (1);
	if (str[i] != ' ' && str[i] != '\t')
		return (1);
	if (ft_check_three(str, &i))
		return (1);
	if (str[i] != ' ' && str[i] != '\t')
		return (1);
	if (ft_check_one(str, &i))
		return (1);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] != '\0' && str[i] != '\n')
		return (1);
	return (0);
}

int	ft_check_L(miniRT *data, char *str, int i)
{
	(data->light_arr_size)++;
	if (ft_check_three(str, &i))
		return (1);
	if (str[i] != ' ' && str[i] != '\t')
		return (1);
	if (ft_check_one(str, &i))
		return (1);
	if (str[i] != ' ' && str[i] != '\t')
		return (1);
	if (ft_check_three(str, &i))
		return (1);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] != '\0' && str[i] != '\n')
		return (1);
	return (0);
}

int	ft_check_sp(miniRT *data, char *str, int i)
{
	(data->sphere_arr_size)++;
	if (ft_check_three(str, &i))
		return (1);
	if (str[i] != ' ' && str[i] != '\t')
		return (1);
	if (ft_check_one(str, &i))
		return (1);
	if (str[i] != ' ' && str[i] != '\t')
		return (1);
	if (ft_check_three(str, &i))
		return (1);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] != '\0' && str[i] != '\n')
		return (1);
	return (0);
}

int	ft_check_pl(miniRT *data, char *str, int i)
{
	(data->plane_arr_size)++;
	if (ft_check_three(str, &i))
		return (1);
	if (str[i] != ' ' && str[i] != '\t')
		return (1);
	if (ft_check_three(str, &i))
		return (1);
	if (str[i] != ' ' && str[i] != '\t')
		return (1);
	if (ft_check_three(str, &i))
		return (1);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] != '\0' && str[i] != '\n')
		return (1);
	return (0);
}

int	ft_check_cy(miniRT *data, char *str, int i)
{
	(data->cylinder_arr_size)++;
	if (ft_check_three(str, &i))
		return (1);
	if (str[i] != ' ' && str[i] != '\t')
		return (1);
	if (ft_check_three(str, &i))
		return (1);
	if (str[i] != ' ' && str[i] != '\t')
		return (1);
	if (ft_check_one(str, &i))
		return (1);
	if (str[i] != ' ' && str[i] != '\t')
		return (1);
	if (ft_check_one(str, &i))
		return (1);
	if (str[i] != ' ' && str[i] != '\t')
		return (1);
	if (ft_check_three(str, &i))
		return (1);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] != '\0' && str[i] != '\n')
		return (1);
	return (0);
}
*/