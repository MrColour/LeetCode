/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0010.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 05:09:12 by kmira             #+#    #+#             */
/*   Updated: 2019/11/21 06:29:33 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

bool	isMatch(char *s, char *p)
{
	int		i;
	char	find;
	bool	result;

	result = false;
	if (*p == '\0')
		return (true);
	if (*p == '.')
	{
		s++;
		p++;
		return (isMatch(s, p));
	}
	else if (*p == '*')
	{
		i = 0;
		find = *(p - 1);
		while (s[i] != '\0')
		{
			if (find == s[i])
			{
				s++;
				p++;
				result |= isMatch(s, p);
				p--;
			}
			i++;
		}
	}
	else
	{
		while (*p && *p == *s)
		{
			p++;
			s++;
		}
	}
	if (*p == '\0')
		return (true);
	return (result);
}

int	main(int aa, char **args)
{
	bool result;

	result = false;
	if (aa == 3)
		result = isMatch(args[1], args[2]);
	else
		printf("Not enough arguements\n");
	if (result)
		printf("TRUE\n");
	else
		printf("FALSE\n");
	return(0);
}
