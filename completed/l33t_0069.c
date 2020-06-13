/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0069.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 21:27:44 by kmira             #+#    #+#             */
/*   Updated: 2019/11/22 21:42:03 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	mySqrt(int x)
{
	int	i;

	i = 0;
	while (i * i < x)
	{
		i++;
	}
	if (i * i > x)
		i--;
	return (i);
}

int	main(int aa, char **args)
{
	int	result;

	result = -42;
	if (aa == 2)
		result = mySqrt(atoi(args[1]));
	else
		printf("Not enough arguements\n");
	printf("NUM: %d\n", result);
	return (0);
}
