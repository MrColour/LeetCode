/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0169.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 21:03:46 by marvin            #+#    #+#             */
/*   Updated: 2019/11/24 21:03:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int majorityElement(int* nums, int numsSize)
{
	int	i;
	int	current;
	int	vote;

	i = 0;
	vote = 0;
	while (i < numsSize)
	{
		if (vote == 0)
			current = nums[i];
		if (nums[i] == current)
			vote++;
		else
			vote--;
		i++;
	}
	return (current);
}

