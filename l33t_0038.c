/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0038.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:06:02 by kmira             #+#    #+#             */
/*   Updated: 2019/11/22 15:07:14 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char *countAndSay(int n)
{
	int		i;
	char	*result;
	char	*cp;

	result = malloc(sizeof(*result) * (2));
	cp = result;
	bzero(result, sizeof(*result) * (2));
	result[0] = 1 + '0';

	int		new_length;
	int		j;
	char	record;
	int		amount;
	int		at;

	i = 1;
	while (i < n)
	{
		new_length = strlen(result) + 1;
		result = malloc(sizeof(*result) * (new_length * 2));
		bzero(result, sizeof(*result) * (new_length * 2));

		j = 0;
		at = 0;
		while (cp[j] != '\0')
		{
			amount = 0;
			record = cp[j];
			while (cp[j] != '\0' && cp[j] == record)
			{
				amount++;
				j++;
			}
			result[at++] = amount + '0';
			result[at++] = record;
		}

		cp = result;
		i++;
	}
	return (result);
}
