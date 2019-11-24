/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0111.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:36:27 by kmira             #+#    #+#             */
/*   Updated: 2019/11/23 18:13:58 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

struct TreeNode
{
	int				val;
	struct TreeNode	*left;
	struct TreeNode	*right;
};

int minDepth(struct TreeNode* root)
{
	int	left_depth;
	int	right_depth;

	if (root == NULL)
		return (0);
	if (root->left == NULL && root->right == NULL)
		return (1);

	left_depth = -1;
	if (root->left)
		left_depth = minDepth(root->left);
	right_depth = -1;
	if (root->right)
		right_depth = minDepth(root->right);

	if (left_depth <= -1)
	{
		if (right_depth <= -1 && right_depth < left_depth)
			return (right_depth + 1);
		else
			return (left_depth + 1);
	}
	else
		return (right_depth + 1);
}

