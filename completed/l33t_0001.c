/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0001.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 01:00:23 by kmira             #+#    #+#             */
/*   Updated: 2019/11/20 01:02:09 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Note: The returned array must be malloced, assume caller calls free().
*/

int	*twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	int i;
	int j;
	int *result;

	i = 0;
	*returnSize = 2;
	result = malloc((sizeof(*result)) * (*returnSize));
	while (i < numsSize)
	{
		j = i + 1;
		while (j < numsSize)
		{
			if (nums[i] + nums[j] == target)
			{
				result[0] = i;
				result[1] = j;
				return (result);
			}
			j++;
		}
		i++;
	}
	return (result);
}
