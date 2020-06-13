/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0155.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 01:30:59 by kmira             #+#    #+#             */
/*   Updated: 2019/11/24 03:01:29 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #TODO Need to redo stack but with two structures. They are allowed. Will make
// things so much easier.

#include <stdlib.h>

typedef struct
{
	int	val;
	int	min;
	int	null;
	void *top;
	void *next;
}		MinStack;

/** initialize your data structure here. */

MinStack *minStackCreate(void)
{
	MinStack	*result;

	result = malloc(sizeof(*result));
	result->null = 1;
	result->next = NULL;
	result->top = result;
	return (result);
}

void minStackPush(MinStack *obj, int x)
{
	MinStack	*new_elem;

	new_elem = malloc(sizeof(*obj));
	new_elem->val = x;
	if (((MinStack *)obj->top)->null != 1)
	{
		if (((MinStack *)obj->top)->min > new_elem->val)
			new_elem->min = x;
		else
			new_elem->min = ((MinStack *)obj->top)->min;
	}
	else
		new_elem->min = x;
	new_elem->null = 0;
	new_elem->top = NULL;
	new_elem->next = obj->top;
	obj->top = new_elem;
}

void minStackPop(MinStack *obj)
{
	if (((MinStack *)obj->top)->null == 1)
		return ;
	else
		obj->top = ((MinStack *)obj->top)->next;
}

int minStackTop(MinStack *obj)
{
	if (((MinStack *)obj->top)->null == 1)
		return (0);
	return (((MinStack *)obj->top)->val);
}

int minStackGetMin(MinStack *obj)
{
	if (((MinStack *)obj->top)->null == 1)
		return (0);
	return (((MinStack *)obj->top)->min);
}

void minStackFree(MinStack *obj)
{
	return ;
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);

 * minStackPop(obj);

 * int param_3 = minStackTop(obj);

 * int param_4 = minStackGetMin(obj);

 * minStackFree(obj);
*/
