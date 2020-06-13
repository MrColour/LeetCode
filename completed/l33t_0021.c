/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0021.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 02:52:59 by kmira             #+#    #+#             */
/*   Updated: 2019/11/22 03:25:11 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>



struct ListNode
{
	int				val;
	struct ListNode	*next;
};


struct ListNode	*mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
	struct ListNode *at;
	struct ListNode *head;

	head = l2;
	if (l2->val < l1->val)
		head = l2;
	at = head;
	while (l1 || l2)
	{
		if (l1 == NULL)
		{
			at->next = l2;
			l2 = l2->next;
			at = at->next;
		}
		else if (l2 == NULL)
		{
			at->next = l1;
			l1 = l1->next;
			at = at->next;
		}
		else if (l1->val < l2->val)
		{
			at->next = l1;
			l1 = l1->next;
			at = at->next;
		}
		else
		{
			at->next = l2;
			l2 = l2->next;
			at = at->next;
		}
	}
	return (head);
}

int	main(void)
{

	return (0);
}
