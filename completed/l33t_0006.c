/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0006.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 23:08:15 by kmira             #+#    #+#             */
/*   Updated: 2019/11/21 06:31:57 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void	get_top(char *str, int numRows, char *result, int *at)
{
	char	*end;

	end = str + strlen(str);
	while (str < end)
	{
		result[*at] = *str;
		str = str + (numRows - 2); //The down;
		str = str + (numRows - 2); //The zag;
		str = str + 2;			   //The tips;
		*at = *at + 1;
	}
}

void	get_middle(char *str, int numRows, char *result, int *at)
{
	char	*end;
	char	*first;
	char	*second;
	int		delta;
	int		amount;

	amount = 0;
	end = str + strlen(str);
	while (amount < (numRows - 2))
	{
		first = str + amount + 1;
		delta = (numRows - 2) + (numRows - 2) + 2;
		second = str + delta - (amount + 1);
		while (first < end)
		{
			result[*at] = *first;
			first += delta;
			*at = *at + 1;

			if (second < end)
			{
				result[*at] = *second;
				*at = *at + 1;
			}
			second += delta;
		}
		amount++;
	}
}

void	get_bottom(char *str, int numRows, char *result, int *at)
{
	char	*end;

	end = str + strlen(str);
	str = str + (numRows - 2) + 1;
	while (str < end)
	{
		// printf("C: %c\n", *str);
		result[*at] = *str;
		str = str + (numRows - 2); //The down;
		str = str + (numRows - 2); //The zag;
		str = str + 2;			   //The tips;
		*at = *at + 1;
	}
}

char	*convert(char *s, int numRows)
{
	int		i;
	char	*result;

	i = 0;
	result = malloc(sizeof(*result) * (strlen(s) + 1));
	bzero(result, sizeof(*result) * (strlen(s) + 1));
	if (numRows == 1)
		return (s);
	get_top(s, numRows, result, &i);
	// printf("TOP: %s\n", result);
	if (numRows > 2)
		get_middle(s, numRows, result, &i);
	// printf("MID: %s\n", result);
	get_bottom(s, numRows, result, &i);
	// printf("BOT: %s\n", result);
	return (result);
}

int	main(void)
{
	printf("STR: %s\n", convert("PTAOT", 3));
	printf("STR: %s\n", convert("PTAOT", 2));
	printf("STR: %s\n", convert("PTAOT", 1));
	return (0);
}
