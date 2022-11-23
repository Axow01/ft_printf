/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcott <mmarcott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:44:51 by mmarcott          #+#    #+#             */
/*   Updated: 2022/11/23 03:03:04 by mmarcott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	output_type(va_list list, char c)
{
	if (c == 'd')
		return (ft_putnbr_fd(va_arg(list, int), STDOUT_FILENO));
	if (c == 's')
		return (ft_putstr_fd(va_arg(list, char *), STDOUT_FILENO));
	return (0);
}

int	ft_printf(char *string, ...)
{
	va_list	args;
	int		i;
	int		total;

	i = 0;
	total = ft_strlen(string);
	va_start(args, string);
	while (string[i])
	{
		if (string[i] != '%')
			ft_putchar_fd(string[i], 1);
		else
		{
			if (string[i + 1] == 0)
				continue ;
			total += output_type(args, string[++i]);
		}
		i++;
	}
	va_end(args);
	return (total);
}

int	main(void)
{
	char	*test;
	int		a;

	test = "bonjour";
	a = ft_printf("%dBonjour les gens %d %s %d\n%s", 10, 32, test, 45,
			"bonsoir");
	ft_printf("%d\n", a);
	return (0);
}
