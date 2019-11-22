/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0003.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 02:01:22 by kmira             #+#    #+#             */
/*   Updated: 2019/11/20 19:31:14 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	lengthOfLongestSubstring(char * s)
{
	int		max;
	int		curr_max;
	char	*dups[127];

	max = 0;
	curr_max = 0;
	memset(dups, 0, sizeof(dups));
	while (*s != '\0')
	{
		if (dups[*s] == NULL)
		{
			dups[*s] = s;
			curr_max++;
		}
		else
		{
			if (max < curr_max)
				max = curr_max;
			s = dups[*s];
			memset(dups, 0, sizeof(dups));
			curr_max = 0;
		}
		s++;
	}
	if (max < curr_max)
		max = curr_max;
	return (max);
}

// int		main(void)
// {
// 	int a = lengthOfLongestSubstring("aab");
// 	printf("%d\n", a);
// 	return (0);
// }
