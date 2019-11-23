/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0104.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 00:16:56 by kmira             #+#    #+#             */
/*   Updated: 2019/11/23 00:21:06 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct TreeNode
{
	int				val;
	struct TreeNode	*left;
	struct TreeNode	*right;
};

#include <string.h>

int maxDepth(struct TreeNode* root)
{
	if (root == NULL)
		return (0);

	int	left_max;
	int	right_max;
	int	max;

	left_max = maxDepth(root->left);
	right_max = maxDepth(root->left);

	if (left_max > right_max)
		max = left_max;
	else
		max = right_max;
	return (max + 1);
}

