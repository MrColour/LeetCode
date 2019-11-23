/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0100.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 23:20:37 by kmira             #+#    #+#             */
/*   Updated: 2019/11/22 23:28:18 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <string.h>

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	bool result;

	result = true;
	if (p != NULL || q != NULL)
	{
		if (p != NULL && q != NULL)
			result = true;
		else
			return (false);
	}
	if (p->left || q->left)
	{
		if (p->left && q->left && result == true)
			result = isSameTree(p->left, q->left);
		else
			return (false);
	}
	if (p->val == q->val)
		result = true;
	else
		return (false);
	if (p->right || q->right)
	{
		if (p->right && q->right && result == true)
			result = isSameTree(p->right, q->right);
		else
			return (false);
	}
	return (result);
}
