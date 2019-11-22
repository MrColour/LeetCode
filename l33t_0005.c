/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0005.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 21:20:08 by kmira             #+#    #+#             */
/*   Updated: 2019/11/20 23:05:08 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		is_palindrome(char *str, int n)
{
	int	i;

	i = 0;
	if (n == 1 || n == 0)
		return (1);
	n = n - 1;
	while (i < n)
	{
		if (str[i] == str[n])
		{
			i++;
			n--;
		}
		else
			break ;
	}
	if (str[i] == str[n] || i > n)
		return (1);
	return (0);
}

char	*longestPalindrome(char *s)
{
	int		i;
	int		max;
	int		end;
	int		cp_end;
	char	*tmp;
	char	*result;

	i = 0;
	max = 0;
	end = strlen(s);
	cp_end = end;
	if (*s == '\0')
		return ("");
	while (s[i] != '\0')
	{
		cp_end = end - i;
		while (cp_end > max)
		{
			if (is_palindrome(&s[i], cp_end) == 1)
				break ;
			else
				cp_end--;
		}
		if (max < cp_end)
		{
			max = cp_end;
			tmp = &s[i];
		}
		i++;
	}
	result = malloc(sizeof(*result) * (max + 2));
	result = strncpy(result, tmp, max);
	result[max] = '\0';
	return (result);
}

int		main(int aa, char **args)
{
	char	*result;

	result = NULL;
	if (aa != 2)
	{
		printf("Wrong amount of parameters\n");
	}
	else
		result = longestPalindrome(args[1]);
	int a = is_palindrome(args[1], strlen(args[1]));
	printf("NUM %d\n", a);
	printf("STRING: %s\n", result);
	return (0);
}
