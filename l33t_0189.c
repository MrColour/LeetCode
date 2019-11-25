/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0189.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 22:46:39 by marvin            #+#    #+#             */
/*   Updated: 2019/11/24 22:46:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void rotate(int* nums, int numsSize, int k)
{
	int	*tmp;

	if (numsSize == 0 || numsSize == 1)
		return ;
	k = k % numsSize;
	tmp = malloc(sizeof(*tmp) * (k));
	memmove(tmp, &nums[numsSize - k], sizeof(*nums) * (k));
	memmove(&nums[k], nums, sizeof(*nums) * (numsSize - k));
	memmove(nums, tmp, sizeof(*nums) * k);
	free(tmp);
}

