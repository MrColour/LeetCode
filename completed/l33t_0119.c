/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0119.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 18:40:39 by kmira             #+#    #+#             */
/*   Updated: 2019/11/23 19:07:21 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/*
** The binomial theorm produces a Pascal's triangle.
*/

int *getRow(int rowIndex, int *returnSize)
{
	int	i;
	int	x;
	int	a;
	int	factor;
	int	*result;

	rowIndex = rowIndex + 1;
	result = malloc(sizeof(*result) * (rowIndex + 1));
	*returnSize = rowIndex;

	a = 1;
	factor = 1;
	x = rowIndex - 1;

	i = 1;
	result[0] = factor;
	while (i < rowIndex)
	{
		factor = (factor * x) / a;
		result[i] = factor;
		x--;
		a++;
		i++;
	}
	return (result);
}

int	main(int aa, char **args)
{
	int	returnSize;
	int	*result;

	if (aa == 2)
		result = getRow(atoi(args[1]), &returnSize);
	else
		printf("Not enough arguements\n");

	int i;

	i = 0;
	while (i < returnSize)
	{
		printf("%d ", result[i]);
		i++;
	}
	return (0);
}
