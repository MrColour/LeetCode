/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0011.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 02:42:25 by kmira             #+#    #+#             */
/*   Updated: 2019/11/27 02:59:09 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		calc_max(int *arr, int length)
{
	int	i;
	int	max;
	int	curr_max;
	int	pillar;

	i = 1;
	max = 0;
	pillar = arr[0];
	while (i < length)
	{
		if (pillar < arr[i])
			curr_max = pillar * i;
		else
			curr_max = arr[i] * i;
		if (curr_max > max)
			max = curr_max;
		i++;
	}
	return (max);
}

int maxArea(int *height, int heightSize)
{
	int	i;
	int	max;
	int	curr_max;

	i = 0;
	max = 0;
	while (i < heightSize)
	{
		if (height[i] == 0)
		{
			i++;
			continue ;
		}
		else
			curr_max = calc_max(&height[i], heightSize - i);
		if (curr_max > max)
			max = curr_max;
		i++;
	}
	return (max);
}
