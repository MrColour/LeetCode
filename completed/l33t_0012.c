/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0012.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 03:12:00 by kmira             #+#    #+#             */
/*   Updated: 2019/11/27 05:07:00 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

#define VAL 0
#define ROM 1

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

// char *intToRoman(int num)
// {
// 	int		i;
// 	int		at;
// 	int		delta;
// 	char	*result;
// 	int		**converter;

// 	result = malloc(sizeof(*result) * (20));
// 	bzero(result, sizeof(*result) * (20));
// 	converter = get_transform();
// 	while (num > 0)
// 	{
// 		// printf("NUM: %d, %d\n", num, i);
// 		if (i != 6 && i % 2 == 0)
// 			delta =	converter[6 - i - 2][VAL];
// 		else if (i != 6)
// 			delta = converter[6 - i - 1][VAL];
// 		if (i == 6)
// 			delta = 0;
// 		if (num >= converter[6 - i][VAL] - delta)
// 		{
// 			while (num > converter[6 - i][VAL] - delta)
// 			{
// 				printf("%c", converter[6 - i][ROM]);
// 				num -= converter[6 - i][VAL];
// 			}
// 			if (num == 1)
// 			{
// 				printf("%c", converter[0][ROM]);
// 				num = 0;
// 			}
// 			if (num >= converter[6 - i][VAL] - delta)
// 			{
// 				if (i % 2 == 0 && i != 0)
// 					printf("%c", converter[6 - i - 2][ROM]);
// 				else
// 					printf("%c", converter[6 - i - 1][ROM]);
// 				printf("%c", converter[6 - i][ROM]);
// 				num -= converter[6 - i][VAL];
// 			}
// 		}
// 		// printf("ENUM: %d\n", num);
// 		i++;
// 	}
// 	return (NULL);
// }

char * intToRoman(int num)
{
	int		at;
	char	*result;

	at = 0;
	result = malloc(sizeof(*result) * (20));
	bzero(result, sizeof(*result) * (20));

	while (num > 0)
	{
		if (num >= 1000)
		{
			result[at++] = 'M';
			num -= 1000;
		}
		else if (num >= 500)
		{
			if (900 <= num)
			{
				result[at++] = 'C';
				result[at++] = 'M';
				num -= 900;
			}
			else
			{
				result[at++] = 'D';
				num -= 500;
			}
		}
		else if (num >= 100)
		{
			if (400 <= num)
			{
				result[at++] = 'C';
				result[at++] = 'D';
				num -= 400;
			}
			else
			{
				result[at++] = 'C';
				num -= 100;
			}
		}
		else if (num >= 50)
		{
			if (90 <= num)
			{
				result[at++] = 'X';
				result[at++] = 'C';
				num -= 90;
			}
			else
			{
				result[at++] = 'L';
				num -= 50;
			}
		}
		else if (num >= 10)
		{
			if (40 <= num)
			{
				result[at++] = 'X';
				result[at++] = 'L';
				num -= 40;
			}
			else
			{
				result[at++] = 'X';
				num -= 10;
			}
		}
		else if (num >= 5)
		{
			if (9 <= num)
			{
				result[at++] = 'I';
				result[at++] = 'X';
				num -= 9;
			}
			else
			{
				result[at++] = 'V';
				num -= 5;
			}
		}
		else
		{
			if (4 <= num)
			{
				result[at++] = 'I';
				result[at++] = 'V';
				num -= 4;
			}
			else
			{
				result[at++] = 'I';
				num -= 1;
			}
		}
	}
	return (result);
}


int	main(int aa, char **args)
{
	// if (aa == 2)
	// 	intToRoman(atoi(args[1]));
	// else
	// 	printf("Not enough arguements\n");

	int	stop;
	int	start;
	int	offset;

	offset = 993;
	start = 1;
	stop = 10;
	while (start < stop)
	{
		printf("%s\n", intToRoman(start + offset));
		start++;
	}
	return (0);
}
