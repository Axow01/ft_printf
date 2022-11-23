/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:44:51 by mmarcott          #+#    #+#             */
/*   Updated: 2022/11/23 01:43:06 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	counting(char *string)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (string[i])
	{
		if (string[i] == '%' && !(string[i + 1] == '%' || string[i + 1] == '\0'
				|| string[i + 1] == ' '))
			count++;
		i++;
	}
	return (count);
}

void	ft_printf(char *string, ...)
{
	//va_list	args;
	//va_start(args, counting(string));
	printf("Count: %d\n", counting(string));
}

int	main(void)
{
	ft_printf("Bonjour les gens %s %% %a");
	return (0);
}
