/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0167.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 04:36:49 by kmira             #+#    #+#             */
/*   Updated: 2019/11/24 04:42:20 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int *twoSum(int *numbers, int numbersSize, int target, int *returnSize)
{
	int	min;
	int	max;
	int	*result;

	result = malloc(sizeof(*result) * (2));
	*returnSize = 2;

	min = 0;
	max = numbersSize - 1;
	while (min < max)
	{
		if (numbers[min] + numbers[max] == target)
		{
			result[0] = min;
			result[1] = max;
			return (result);
		}
		if (numbers[min] + numbers[max] > target)
			max--;
		else
			min++;
	}
	return (result);
}

