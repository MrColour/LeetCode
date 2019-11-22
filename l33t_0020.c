/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0020.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 01:25:46 by kmira             #+#    #+#             */
/*   Updated: 2019/11/22 02:49:27 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

int		is_paran(char c)
{
	if (c == '(' || c == '{' || c == '[')
		return (1);
	return (0);
}

int		is_closing(char c)
{
	if (c == ')' || c == '}' || c == ']')
		return (1);
	return (0);
}

int		is_pair(char open, char close)
{
	if (open == '(' && close == ')')
		return (1);
	if (open == '{' && close == '}')
		return (1);
	if (open == '[' && close == ']')
		return (1);
	return (0);
}

void	recurrsive_call(char *str, int *i, bool *result, char *check)
{
	char	new_check;

	*i = *i + 1;
	while (str[*i] != '\0' && *result == true)
	{
		if (is_paran(str[*i]))
		{
			new_check = str[*i];
			recurrsive_call(str, i, result, &new_check);
			if (new_check != '\0')
				*result = false;
		}
		else if (is_closing(str[*i]))
		{
			if (is_pair(*check, str[*i]) == 0)
				*result = false;
			else
				*check = '\0';
			if (str[*i] != '\0')
				*i = *i + 1;
			break ;
		}
		else
			*i = *i + 1;
	}
}

bool	isValid(char *s)
{
	int		i;
	bool	result;
	char	check;

	i = -1;
	result = true;
	check = '\0';
	recurrsive_call(s, &i, &result, &check);
	return (result);
}

int	main(int aa, char **args)
{
	bool	result;

	result = false;
	if (aa == 2)
		result = isValid(args[1]);
	else
		printf("Not enough arguements\n");
	if (result == true)
		printf("TRUE\n");
	else
		printf("FALSE\n");
	return (0);
}
