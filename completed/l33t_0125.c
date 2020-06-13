/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0125.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 22:10:54 by kmira             #+#    #+#             */
/*   Updated: 2019/11/23 22:25:11 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool isPalindrome(char *s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i] != '\0' && isalnum(s[i]) == 0)
		i++;
	j = strlen(s);
	while (i < j)
	{
		while (s[i] != '\0' && isalnum(s[i]) == 0)
			i++;
		while (j > 0 && isalnum(s[j]) == 0)
			j--;
		if (tolower(s[i]) != tolower(s[j]))
			return (false);
		i++;
		j--;
	}
	return (true);
}

int	main(int aa, char **args)
{
	bool result;

	result = false;
	if (aa == 2)
		result = isPalindrome(args[1]);
	else
		printf("Not enough arguements\n");
	if (result)
		printf("TRUE\n");
	else
		printf("FALSE\n");
	return (0);
}
