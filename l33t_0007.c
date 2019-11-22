/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0007.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 00:39:54 by kmira             #+#    #+#             */
/*   Updated: 2019/11/21 01:14:19 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	reverse(int x)
{
	int64_t	result;
	char		sign;

	printf("NUM: %d\n", x);
	result = 0;
	while (x != 0)
	{
		result = result * 10 + (x % 10);
		x = x / 10;
	}
	if (-2147483648 < result && result < 0X7FFFFFFF)
		return ((int)result);
	return (0);
}

// int		main(int aa, char **args)
// {
// 	int	a;

// 	a = -42;
// 	if (aa == 2)
// 		a = reverse(atoi(args[1]));
// 	else
// 		printf("Not enough params\n");
// 	printf("NUM: %d\n", a);
// 	return (0);
// }

// 2147483647
