/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0112.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:58:00 by kmira             #+#    #+#             */
/*   Updated: 2019/11/23 18:11:08 by kmira            ###   ########.fr       */
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

bool hasPathSum(struct TreeNode* root, int sum)
{
	bool	result;

	result = false;

	if (root == NULL)
		return (false);

	if (root->left == NULL && root->right == NULL && sum == root->val)
		return (true);

	if (root->left)
		result = hasPathSum(root->left, sum - root->val);
	if (root->right && result == false)
		result = hasPathSum(root->right, sum - root->val);
	return (result);
}

