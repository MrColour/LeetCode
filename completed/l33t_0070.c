/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0070.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 21:46:27 by kmira             #+#    #+#             */
/*   Updated: 2019/11/22 22:00:03 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	climbStairs(int n)
{
	int	i;
	int	*dyna;

	if (n <= 2)
		return (n);
	dyna = malloc(sizeof(*dyna) * (n + 3));
	bzero(dyna, sizeof(*dyna) * (n + 3));
	i = 2;
	dyna[0] = 0;
	dyna[1] = 1;
	dyna[2] = 2;
	while (i < n)
	{
		dyna[i + 1] = dyna[i] + dyna[i - 1];
		i++;
	}
	return (dyna[n]);
}

int	main(int aa, char **args)
{
	int	result;

	result = -42;
	if (aa == 2)
		result = climbStairs(atoi(args[1]));
	else
		printf("Not enough arguements\n");
	printf("RES: %d\n", result);
	return (0);
}
