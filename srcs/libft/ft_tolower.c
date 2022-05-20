/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:55:01 by bgenie            #+#    #+#             */
/*   Updated: 2022/04/11 14:23:03 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c < 0 || c > 127)
		return (c);
	if ((unsigned char) c >= 'A' && (unsigned char) c <= 'Z')
		return (c + 32);
	return (c);
}
