/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0014.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 22:37:38 by kmira             #+#    #+#             */
/*   Updated: 2019/11/22 01:25:38 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*longestCommonPrefix(char ** strs, int strsSize)
{
	int		i;
	int		tmp;
	int		length;
	char	*result;

	i = 0;
	length = 0;
	if (strsSize == 0)
		return ("");
	while (i < strsSize)
	{
		tmp = strlen(strs[i]);
		if (length < tmp)
			length = tmp;
		i++;
	}

	result = malloc(sizeof(*result) * (length + 2));
	bzero(result, sizeof(*result) * (length + 1));

	char	check;
	int		at;
	int		check_next;

	i = 0;
	at = 0;
	check_next = 1;
	while (check_next == 1)
	{
		i = 0;
		check = strs[0][at];
		while (i < strsSize)
		{
			if (strs[i][at] != '\0' && strs[i][at] == check)
				i++;
			else
			{
				check_next = 0;
				break ;
			}
		}
		if (check_next == 1)
			result[at] = check;
		at++;
	}
	return (result);
}

#define SIZE 3

int	main(void)
{
	char	*arr[SIZE + 1];
	char	*result;

	result = NULL;
	arr[0] = "flw";
	arr[1] = "flw";
	arr[2] = "flo";
	result = longestCommonPrefix(arr, 0);
	printf("PREFIX: %s\n", result);
	return (0);
}
