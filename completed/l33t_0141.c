/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0141.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 01:06:36 by kmira             #+#    #+#             */
/*   Updated: 2019/11/24 01:18:07 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct ListNode
{
	int				val;
	struct ListNode	*next;
};

#include <stdbool.h>
#include <stddef.h>

bool hasCycle(struct ListNode *head)
{
	int				count;
	struct ListNode	*iter;

	iter = head;
	if (iter == NULL)
		return (-1);
	if (iter->next == NULL)
		return (1);

	iter = iter->next;
	while (head != NULL)
	{
		if (head == iter)
			return (-1);
		if (iter->next && iter->next->next)
			iter = iter->next->next;
		head = head->next;
		count++;
	}
	return (count);
}
