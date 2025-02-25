/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:35:44 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/19 18:32:38 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "custom_builtins.h"
#include "minishell.h"
#include "struct.h"

static int	is_numeric(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (ft_strcmp(str, "") == 0)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	builtin_exit(t_minishell *minishell, char **args)
{
	if (!minishell)
		return ;
	if (!args[1])
	{
		minishell->exit_status = 0;
		cleanup_main(minishell);
	}
	if (!is_numeric(args[1]))
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(args[1], 2);
		ft_putendl_fd(": numeric argument required", 2);
		minishell->exit_status = 255;
		cleanup_main(minishell);
	}
	if (args[2])
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putendl_fd("too many arguments", 2);
		minishell->exit_status = 1;
		cleanup_main(minishell);
	}
	minishell->exit_status = (unsigned char)ft_atoi(args[1]);
	cleanup_main(minishell);
}
