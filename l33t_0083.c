/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0083.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 22:06:30 by kmira             #+#    #+#             */
/*   Updated: 2019/11/22 22:13:14 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct ListNode
{
	int				val;
	struct ListNode	*next;
};

#include <string.h>

struct ListNode *deleteDuplicates(struct ListNode *head)
{
	struct ListNode *prev;
	struct ListNode *iter;

	if (head == NULL || head->next == NULL)
		return (head);
	prev = head;
	iter = prev->next;
	while (iter)
	{
		if (prev->val == iter->val)
			prev->next = iter->next;
		else
			prev = iter;
		iter = iter->next;
	}
	return (head);
}

