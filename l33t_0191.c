/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0191.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 19:24:53 by kmira             #+#    #+#             */
/*   Updated: 2019/11/25 20:03:14 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

int rob(int *nums, int numsSize)
{
	int	i;
	int	sum;
	int	*holder;

	if (numsSize == 0)
		return (0);
	else if (numsSize == 1)
		return (nums[0]);
	else if (numsSize == 2)
		return (nums[0] > nums[1] ? nums[0] : nums[1]);

	i = numsSize - 1 - 3;
	holder = malloc(sizeof(*nums) * (numsSize));
	bzero(holder, sizeof(*nums) * (numsSize));
	while (i >= 0)
	{
		if (holder[i + 2] > holder[i + 3])
			sum = holder[i + 2];
		else
			sum = holder[i + 3];
		holder[i] = sum + nums[i];
		i--;
	}
	if (holder[0] > holder[1])
		return (holder[0]);
	else
		return (holder[1]);
}

