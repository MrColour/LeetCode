/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0160.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 04:01:51 by kmira             #+#    #+#             */
/*   Updated: 2019/11/24 04:30:54 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

struct ListNode
{
	int				val;
	struct ListNode	*next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
	struct ListNode	*runner_1;
	struct ListNode	*runner_2;

	if (headA == NULL || headB == NULL)
		return (NULL);
	runner_1 = headA;
	runner_2 = headB;
	while (runner_1 != runner_2)
	{
		if (runner_1 == NULL)
			runner_1 = headB;
		if (runner_2 == NULL)
			runner_2 = headA;
		runner_1 = runner_1->next;
		runner_2 = runner_2->next;
	}
	return (runner_1);
}
