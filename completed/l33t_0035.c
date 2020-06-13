/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0035.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 18:13:03 by kmira             #+#    #+#             */
/*   Updated: 2019/11/23 18:13:06 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int searchInsert(int *nums, int numsSize, int target)
{
	int	start;
	int	middle;
	int	end;

	start = 0;
	end = numsSize;
	middle = (end - start) / 2;
	while (end - start > 1)
	{
		if (nums[middle] > target)
		{
			end = middle;
			middle = start + (end - start) / 2;
		}
		else
		{
			start = middle;
			middle = start + (end - start) / 2;
		}
	}

	if (nums[middle] == target)
		return (target);
	if (nums[middle] > target)
	{
		while (middle > numsSize && nums[middle] > target)
			middle++;
	}
	else if (nums[middle] > target)
	{
		while (middle < 0 && nums[middle] < target)
			middle--;
	}

	return (middle);
}

int	main(void)
{
	searchInsert((int[5]){0, 1, 2, 3, 4}, 5, 2);
	return (0);
}
