/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0013.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 22:05:04 by kmira             #+#    #+#             */
/*   Updated: 2019/11/21 22:28:53 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROM 0
#define VAL 1

int		**get_transform(void)
{
	int	i;
	int	**result;

	i = 0;
	result = malloc(sizeof(*result) * (7));
	while (i < 7)
	{
		result[i] = malloc(sizeof(**result) * (2));
		if (i % 2 == 0)
			result[i][VAL] = pow(10, (i / 2));
		else
			result[i][VAL] = pow(10, (i / 2)) * 5;
		i++;
	}
	result[0][ROM] = 'I';
	result[1][ROM] = 'V';
	result[2][ROM] = 'X';
	result[3][ROM] = 'L';
	result[4][ROM] = 'C';
	result[5][ROM] = 'D';
	result[6][ROM] = 'M';
	return (result);
}

int	romanToInt(char *s)
{
	int	i;
	int	j;
	int	at;
	int	result;
	int	**converter;

	i = 0;
	at = 6;
	result = 0;
	converter = get_transform();
	while (s[i] != '\0')
	{
		j = 0;
		while (j < 7)
		{
			if (s[i] == converter[j][ROM])
			{
				if (j > at)
				{
					result += (converter[j][VAL] - converter[at][VAL] - converter[at][VAL]);
					at = j;
				}
				else
				{
					at = j;
					result += converter[j][VAL];
				}
				break ;
			}
			j++;
		}
		i++;
	}
	return (result);
}

int		main(int aa, char **args)
{
	int	result;

	result = 0;
	if (aa == 2)
		result = romanToInt(args[1]);
	else
		printf("Not enough arguements\n");
	printf("RES: %d\n", result);
	return (0);
}
