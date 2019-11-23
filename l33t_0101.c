/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0101.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 23:41:47 by kmira             #+#    #+#             */
/*   Updated: 2019/11/23 00:13:00 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <string.h>

struct TreeNode
{
	int				val;
	struct TreeNode	*left;
	struct TreeNode	*right;
};

bool	checker(struct TreeNode *left, struct TreeNode *right)
{
	bool	result;

	result = true;
	if (left == NULL)
	{
		if (right == NULL)
			return (true);
		else
			return (false);
	}
	if (right == NULL)
		return (false);
	result = checker(left->left, right->right);
	if (result == false)
		return (false);
	if (left->val != right->val)
		return (false);
	result = checker(left->right, right->left);
	if (result == false)
		return (false);
	return (result);
}

bool isSymmetric(struct TreeNode *root)
{
	bool	result;

	result = true;
	if (root == NULL)
		return (true);
	result = checker(root->left, root->right);
	return (result);
}

