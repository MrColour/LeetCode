/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l33t_0058.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:05:05 by kmira             #+#    #+#             */
/*   Updated: 2019/11/22 15:05:21 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <string.h>

int lengthOfLastWord(char * s)
{
    int end;
    int result;

    end = strlen(s) - 1;
    while (0 < end && isspace(s[end]))
        end--;
    result = 0;
    while (0 < end)
    {
        if (isspace(s[end]))
            return (result);
        end--;
        result++;
    }
    if (end == 0 && isspace(s[end]) == 0)
        result++;
    return (result);
}

