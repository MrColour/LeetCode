/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0122.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 21:14:23 by kmira             #+#    #+#             */
/*   Updated: 2019/11/23 22:08:21 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

// int maxProfit_o(int *prices, int pricesSize)
// {
// 	int	i;
// 	int	curr_min;
// 	int	result;

// 	i = 0;
// 	if (pricesSize == 0)
// 		return (0);
// 	curr_min = prices[0];
// 	result = prices[0] - curr_min;
// 	while (i < pricesSize)
// 	{
// 		if (curr_min > prices[i])
// 			curr_min = prices[i];
// 		else if (prices[i] - curr_min > result)
// 			result = prices[i] - curr_min;
// 		i++;
// 	}
// 	return (result);
// }

// int maxProfit(int *prices, int pricesSize)
// {
// 	int	i;
// 	int	cut_off;
// 	int	pos_trade;
// 	int	result;

// 	if (pricesSize <= 1)
// 		return (0);
// 	result = 0;
// 	cut_off = 1;
// 	i = pricesSize - 1;
// 	while (i >= 0)
// 	{
// 		pos_trade = maxProfit_o(&prices[i], cut_off);
// 		printf("TRADE: %d at %d with %d\n", pos_trade, prices[i], cut_off);
// 		if (pos_trade > 0)
// 		{
// 			printf("AT: %d and C: %d\n", prices[i], cut_off);
// 			cut_off = 1;
// 			result += pos_trade;
// 		}
// 		else
// 			cut_off++;
// 		i--;
// 	}
// 	return (result);
// }

int maxProfit(int *prices, int pricesSize)
{
	int	i;
	int	prev;
	int	result;

	result = 0;
	if (pricesSize <= 1)
		return (0);
	i = 0;
	prev = prices[0];
	while (i < pricesSize)
	{
		if (prices[i] > prev)
			result += prices[i] - prev;
		prev = prices[i];
		i++;
	}
	return (result);
}

int	main(void)
{
	int	size;
	int	*prices;
	int	result;

	size = 6;
	prices = malloc(sizeof(*prices) * (size + 1));
	prices[0] = 7;
	prices[1] = 1;
	prices[2] = 5;
	prices[3] = 3;
	prices[4] = 6;
	prices[5] = 4;
	size = 3;
	result = maxProfit(prices, size);

	printf("%d\n", result);
	return (0);
}

// [1,2,3,4,5]
