/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0028.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 04:15:19 by kmira             #+#    #+#             */
/*   Updated: 2019/11/22 15:09:18 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>

// int strStr(char *haystack, char *needle)
// {
// 	char *loc;
// 	loc = strstr(haystack, needle);
// 	if (loc == NULL)
// 		return (-1);
// 	return (loc - haystack);
// }

int	strStr(char *haystack, char *needle)
{
	int		i;
	int		j;
	char	inital;

	i = 0;
	if (*needle == '\0')
		return (0);
	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (needle[j] != '\0' && haystack[i + j] != '\0' && needle[j] == haystack[i + j])
			{
				j++;
			}
			if (needle[j] == '\0')
				return (i);
		}
		i++;
	}
	return (-1);
}

#include <stdio.h>

int	main(int aa, char **args)
{
	int	result;

	result = 0;
	if (aa == 3)
		result = strStr(args[1], args[2]);
	else
		printf("Not enough arguements\n");
	printf("INDEX: %d\n", result);
	return (0);
}

