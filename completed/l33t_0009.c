/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0009.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 03:54:22 by kmira             #+#    #+#             */
/*   Updated: 2019/11/21 04:14:33 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

bool	isPalindrome(int x)
{
	int		i;
	int		j;
	char	num[11]; //Assumes (INT_MAX == 2147483647)

	i = 0;
	if (x < 0)
		return (false);
	bzero(num, sizeof(num));
	while (x != 0)
	{
		num[i] = x % 10; //We can add + '0' to make it ascii
		x /= 10;
		i++;
	}
	i--;
	j = 0;
	while (j < i)
	{
		if (num[i] != num[j])
			return (false);
		i--;
		j++;
	}
	return (true);
}

int		main(int aa, char **args)
{
	bool result;

	result = false;
	if (aa == 2)
		result = isPalindrome(atoi(args[1]));
	else
		printf("Not enough params\n");
	if (result)
		printf("TRUE\n");
	else
		printf("FALSE\n");
	return (0);
}
