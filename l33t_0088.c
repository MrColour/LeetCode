/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0088.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 22:21:50 by kmira             #+#    #+#             */
/*   Updated: 2019/11/22 22:39:36 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
	int	at;

	at = nums1Size;
	while (m > 0 && n > 0)
	{
		if (nums1[m] > nums2[n])
		{
			nums1[at] = nums1[m];
			at--;
			m--;
		}
		else
		{
			nums1[at] = nums2[n];
			at--;
			n--;
		}
	}

	while (m > 0)
	{
		nums1[at] = nums1[m];
		at--;
		m--;
	}

	while (n > 0)
	{
		nums1[at] = nums2[n];
		at--;
		n--;
	}

	memcpy(nums1, nums2, sizeof(*nums2) * nums2Size);
}

