/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0202.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:31:43 by kmira             #+#    #+#             */
/*   Updated: 2019/11/27 02:42:23 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
** Another solution is using the Floyd technique.
** This structure could be made better using
** a binary search tree. The problem is memory space.
** The Floyd technique takes an average less than
** 2n to meet up. When the calculation is simple that method should be prefered
** when the calculation is difficult to compute, or is the bottleneck
** this method is better, with a better search algorithm.
*/

typedef struct	s_numbers
{
	struct s_numbers	*next;
	int					number;
}				t_number;

bool	hasOccured(t_number *head, int n)
{
	while (head != NULL)
	{
		if (head->number == n)
			return (true);
		head = head->next;
	}
	return (false);
}

bool	isHappy(int n)
{
	int			tmp;
	t_number	*set;
	t_number	*curr;

	set = malloc(sizeof(*set));
	set->next = NULL;
	set->number = 0; //0 is not a happy number anyways.
	curr = set;
	while (1)
	{
		if (n == 1)
			return (true);
		else if (hasOccured(set, n))
			return (false);
		else
		{
			curr->next = malloc(sizeof(*curr));
			curr = curr->next;
			curr->next = NULL;
			curr->number = n;
		}
		tmp = n;
		n = 0;
		while (tmp)
		{
			n += (tmp % 10) * (tmp % 10);
			tmp /= 10;
		}
	}
	return (0);
}

int	main(int aa, char **args)
{
	bool	result;

	if (aa == 2)
		result = isHappy(atoi(args[1]));
	else
		printf("Not enough arguements\n");
	return (0);
}
