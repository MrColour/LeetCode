/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0066.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:15:24 by kmira             #+#    #+#             */
/*   Updated: 2019/11/22 20:32:42 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

/*
** Note: The returned array must be malloced, assume caller calls free().
*/

int	*plusOne(int *digits, int digitsSize, int *returnSize)
{
	int	i;
	int	carry;
	int	*result;

	i = digitsSize - 1;
	result = malloc(sizeof(*result) * (digitsSize + 1 + 1));
	result = result + 1;

	carry = 1;
	while (i >= 0)
	{
		result[i] = digits[i] + carry;
		if (result[i] == 10)
		{
			result[i] = 0;
			carry = 1;
		}
		else
			carry = 0;
		i--;
	}

	if (i == -1)
		i = 0;
	*returnSize = digitsSize;
	if (carry == 1)
	{
		result = result - 1;
		result[0] = 1;
		*returnSize = *returnSize + 1;
	}

	return (result);
}

int	main(void)
{
	int	i;
	int	size;
	int	arr[5];
	int	*result;

	arr[0] = 0;
	result = plusOne(arr, 1, &size);

	i = 0;
	while (i < size)
	{
		printf("NUM: %d\n", result[i]);
		i++;
	}
	return (0);
}
