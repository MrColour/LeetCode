/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0067.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 20:33:08 by kmira             #+#    #+#             */
/*   Updated: 2019/11/22 21:21:34 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void	add_logic(char b, char a, char *carry, char *result)
{
	if (b + a + *carry == '1' + '1' + '1')
	{
		*carry = '1';
		*result = '1';
	}
	else if (b + a + *carry == '1' + '1' + '0')
	{
		*carry = '1';
		*result = '0';
	}
	else if (b + a + *carry == '1' + '0' + '0')
	{
		*carry = '0';
		*result = '1';
	}
	else
	{
		*carry = '0';
		*result = '0';
	}
}

char	*addBinary(char *a, char *b)
{
	int		at;
	int		a_len;
	int		b_len;
	int		length;
	char	carry;
	char	*result;

	while (*a == '0')
		a++;
	while (*b == '0')
		b++;

	a_len = strlen(a) - 1;
	b_len = strlen(b) - 1;
	if (b_len == -1 && a_len == -1)
		return ("0");
	if (a_len > b_len)
		length = a_len;
	else
		length = b_len;

	result = malloc(sizeof(*result) * (length + 3));
	bzero(result, sizeof(*result) * (length + 3));

	at = 0;
	carry = '0';
	while (b_len >= 0 && a_len >= 0)
	{
		printf("B: %c and %c\n", b[b_len], a[a_len]);
		add_logic(b[b_len], a[a_len], &carry, &result[at]);
		at++;
		b_len--;
		a_len--;
	}

	while (a_len >= 0)
	{
		add_logic('0', a[a_len], &carry, &result[at]);
		a_len--;
		at++;
	}

	while (b_len >= 0)
	{
		add_logic(b[b_len], '0', &carry, &result[at]);
		b_len--;
		at++;
	}

	printf("CAR %c and %s\n", carry, result);
	if (carry == '1')
		result[at] = '1';

	int		i;
	char	tmp;

	i = 0;
	length = strlen(result) - 1;
	while (i < length)
	{
		tmp = result[length];
		result[length] = result[i];
		result[i] = tmp;
		length--;
		i++;
	}

	return (result);
}

int		main(int aa, char **args)
{
	char	*result;

	result = NULL;
	if (aa == 3)
		result = addBinary(args[1], args[2]);
	else
		printf("Not enough arguements\n");
	printf("RES: %s\n", result);
	return (0);
}
