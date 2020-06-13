/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0004.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 19:33:11 by kmira             #+#    #+#             */
/*   Updated: 2019/11/20 21:17:58 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

double	findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	int	i;
	int	i1;
	int	i2;
	int	*complete_arr;

	complete_arr = malloc(sizeof(*complete_arr) * (nums1Size + nums2Size));
	i = 0;
	i1 = 0;
	i2 = 0;
	while (i < nums1Size + nums2Size)
	{
		if (i1 < nums1Size)
		{
			if (i2 < nums2Size)
			{
				if (nums1[i1] < nums2[i2])
					complete_arr[i] = nums1[i1++];
				else
					complete_arr[i] = nums2[i2++];
			}
			else
				complete_arr[i] = nums1[i1++];
		}
		else
			complete_arr[i] = nums2[i2++];
		i++;
	}
	if ((nums1Size + nums2Size) % 2 == 0)
		return ((complete_arr[(nums1Size + nums2Size) / 2] + (double)(complete_arr[(nums1Size + nums2Size) / 2 - 1])) / 2);
	else
		return (complete_arr[(nums1Size + nums2Size) / 2]);
}

// int		main(void)
// {
// 	int	num1[] = {1};
// 	int	num2[] = {2};
// 	double	median;

// 	median = findMedianSortedArrays(num1, 1, num2, 1);
// 	printf("RES: %f\n", median);
// 	return (0);
// }
