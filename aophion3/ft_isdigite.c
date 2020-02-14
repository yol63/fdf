/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romarash <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 14:39:19 by romarash          #+#    #+#             */
/*   Updated: 2020/02/14 15:27:22 by romarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_isdigite(char *ch)
{
	size_t i;

	i = 0;
	while (ch[i] != '\0')
	{
		if ((ch[i] < 48 || ch[i] > 57) && (ch[i] != 45))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_wei(char **split, int wid)
{
	int i;

	i = 0;
	while (split[i] != NULL)
		i++;
	if (wid > i - 1)
		return (0);
	return (1);
}
