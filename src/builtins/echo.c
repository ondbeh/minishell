/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:32:17 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/13 19:07:24 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	is_n_flag(char *arg)
{
	if (!arg || arg[0] != '-')
		return (0);
	if (arg[1] != 'n')
		return (0);
	return (1);
}

int	builtin_echo(char **args)
{
	int	i;
	int	newline;

	if (!args || !args[0])
	{
		ft_putchar_fd('\n', 1);
		return (0);
	}
	newline = 1;
	i = 0;
	while (args[i] && is_n_flag(args[i]))
	{
		newline = 0;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (newline)
		ft_putchar_fd('\n', 1);
	return (0);
}