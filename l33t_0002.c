/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0002.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 01:02:50 by kmira             #+#    #+#             */
/*   Updated: 2019/11/20 01:54:25 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Definition for singly-linked list.
** struct ListNode {
**     int val;
**     struct ListNode *next;
** };
*/

#include <string.h>

struct ListNode
{
	int				val;
	struct ListNode	*next;
};

struct ListNode	*addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	char	carry;
	int		num1;
	int		num2;
	struct ListNode	*result;
	struct ListNode	*prev;
	struct ListNode	*iter;

	carry = 0;
	iter = malloc(sizeof(*iter));
	result = iter;
	while (l1 != NULL || l2 != NULL)
	{
		num1 = 0;
		num2 = 0;
		if (l1 != NULL)
			num1 = l1->val;
		if (l2 != NULL)
			num2 = l2->val;
		iter->val = (num1 + num2) + carry;
		carry = (iter->val) / 10;
		iter->val %= 10;
		if (l1 != NULL)
			l1 = l1->next;
		if (l2 != NULL)
			l2 = l2->next;
		iter->next = malloc(sizeof(*iter));
		prev = iter;
		iter = iter->next;
	}
	if (carry == 1)
	{
		iter->val = 1;
		iter->next = NULL;
	}
	else
	{
		prev->next = NULL;
		free(iter);
	}
	return (result);
}

