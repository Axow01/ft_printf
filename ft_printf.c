/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:44:51 by mmarcott          #+#    #+#             */
/*   Updated: 2022/11/23 02:50:34 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	output_type(va_list list, char c)
{
	if (c == 'd')
		ft_putstr_fd(ft_itoa(va_arg(list, int)), 1);
	if (c == 's')
		ft_putstr_fd(va_arg(list, char *), 1);
	return (0);
}

void	ft_printf(char *string, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, string);
	while (string[i])
	{
		if (string[i] != '%')
			ft_putchar_fd(string[i], 1);
		else
		{
			if (string[i + 1] == 0)
				continue ;
			output_type(args, string[++i]);
		}
		i++;
	}
	va_end(args);
}

int	main(void)
{
	char	*test;

	test = "bonjour";
	ft_printf("Bonjour les gens %d %s %d\n", 10, test, 45);
	return (0);
}
