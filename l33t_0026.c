/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0026.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 03:42:37 by kmira             #+#    #+#             */
/*   Updated: 2019/11/22 03:51:18 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int removeDuplicates(int *nums, int numsSize)
{
	int		i;
	int		*insert;

	i = 0;
	insert = nums;
	while (i < numsSize)
	{
		if (nums[i] != *insert)
		{
			insert++;
			*insert = nums[i];
		}
		i++;
	}
	return (insert - nums + 1);
}

int	main(void)
{
	int i;
	int size;
	int	arr[5];

	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 2;
	arr[4] = 3;

	i = 0;
	size = removeDuplicates(arr, 5);
	while (i < size)
	{
		printf("RES: %d\n", arr[i]);
		i++;
	}
	return (0);
}
