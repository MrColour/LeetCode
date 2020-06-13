/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0008.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 03:24:56 by kmira             #+#    #+#             */
/*   Updated: 2019/11/21 03:50:08 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

int	myAtoi(char *str)
{
	int64_t	result;
	int		sign;

	sign = 1;
	result = 0;
	while (*str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (isdigit(*str))
	{
		result = (result * 10) + (*str - '0');
		if (result > INT32_MAX && sign == 1)
			return (INT32_MAX);
		if (result > INT32_MAX && sign == -1)
			return (INT32_MIN);
		str++;
	}
	result = result * sign;
	if (result > INT32_MAX)
		return (INT32_MAX);
	if (result < INT32_MIN)
		return (INT32_MIN);
	return (result);
}

int	main(int aa , char **args)
{
	int a;

	a = 0;
	if (aa == 2)
		a = myAtoi(args[1]);
	else
		printf("Not enough params\n");
	printf("NUM: %d\n", a);
	return (0);
}
