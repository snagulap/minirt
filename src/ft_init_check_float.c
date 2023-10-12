/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_check_float.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagulap <snagulap@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 09:26:09 by tkilling          #+#    #+#             */
/*   Updated: 2023/10/12 14:58:03 by snagulap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// int	ft_check_float(char *str, int i)
// {
// 	int	count;

// 	while (str[i] == '-' || str[i] == '+' || i > 10000)
// 		i++;
// 	if (!(ft_isdigit(str[i])))
// 		return (1);
// 	count = 0;
// 	while (ft_isdigit(str[i]) && ++count < 10)
// 		i++;
// 	if (ft_isdigit(str[i]))
// 		return (1);
// 	if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\0'
// 		|| str[i] == ',')
// 		return (0);
// 	if (str[i] != '.')
// 		return (1);
// 	i++;
// 	if (!(ft_isdigit(str[i])))
// 		return (1);
// 	count = 0;
// 	while (ft_isdigit(str[i]) && ++count < 10)
// 		i++;
// 	if (ft_isdigit(str[i]))
// 		return (1);
// 	if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\0'
// 		|| str[i] == ',')
// 		return (0);
// 	return (1);
// }

// int	ft_check_three(char *str, int *i)
// {
// 	while (str[*i] == ' ' || str[*i] == '\t')
// 		(*i)++;
// 	if (ft_check_float(str, *i))
// 		return (1);
// 	while (str[*i] == '-' || str[*i] == '+' || ft_isdigit(str[*i])
// 		|| str[*i] == '.')
// 		(*i)++;
// 	if (str[*i] != ',')
// 		return (1);
// 	(*i)++;
// 	if (ft_check_float(str, *i))
// 		return (1);
// 	while (str[*i] == '-' || str[*i] == '+' || ft_isdigit(str[*i])
// 		|| str[*i] == '.')
// 		(*i)++;
// 	if (str[*i] != ',')
// 		return (1);
// 	(*i)++;
// 	if (ft_check_float(str, *i))
// 		return (1);
// 	while (str[*i] == '-' || str[*i] == '+' || ft_isdigit(str[*i])
// 		|| str[*i] == '.')
// 		(*i)++;
// 	return (0);
// }

// int	ft_check_one(char *str, int *i)
// {
// 	while (str[*i] == ' ' || str[*i] == '\t')
// 		(*i)++;
// 	if (ft_check_float(str, *i))
// 		return (1);
// 	while (str[*i] == '-' || str[*i] == '+' || ft_isdigit(str[*i])
// 		|| str[*i] == '.')
// 		(*i)++;
// 	return (0);
// }
