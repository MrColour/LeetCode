/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0118.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 18:14:18 by kmira             #+#    #+#             */
/*   Updated: 2019/11/23 18:27:01 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int	**generate(int numRows, int *returnSize, int **returnColumnSizes)
{
	int		i;
	int		j;
	int		**result;

	result = malloc(sizeof(*result) * (numRows));
	*returnColumnSizes = malloc(sizeof(**returnColumnSizes) * (numRows));
	*returnSize = numRows;

	i = 0;
	while (i < numRows)
	{
		result[i] = malloc(sizeof(**result) * (i + 1));
		(*returnColumnSizes)[i] = i + 1;
		result[i][0] = 1;
		j = 1;
		while (j < i)
		{
			result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
			j++;
		}
		if (i >= 1)
			result[i][j] = 1;
		i++;
	}
	return (result);
}

int	main(int aa, char **args)
{
	int	returnSize;
	int	*returnCol;
	int	**result;

	if (aa == 2)
		result = generate(atoi(args[1]), &returnSize, &returnCol);
	else
		printf("Not enough arguements\n");

	int	i;
	int	j;

	i = 0;
	while (i < returnSize)
	{
		j = 0;
		while (j < returnCol[i])
		{
			printf("%d ", result[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}

	return (0);
}
