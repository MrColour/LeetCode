/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0121.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:44:42 by kmira             #+#    #+#             */
/*   Updated: 2019/11/23 21:33:57 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



int maxProfit(int *prices, int pricesSize)
{
	int	i;
	int	curr_min;
	int	result;

	i = 0;
	if (pricesSize == 0)
		return (0);
	curr_min = prices[0];
	result = prices[0] - curr_min;
	while (i < pricesSize)
	{
		if (curr_min > prices[i])
			curr_min = prices[i];
		else if (prices[i] - curr_min > result)
			result = prices[i] - curr_min;
		i++;
	}
	return (result);
}

