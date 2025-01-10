/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_external.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:41:01 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/10 12:53:16 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	execute_external_command(t_minishell *mini, t_ast_node *ast)
{
	pid_t	pid;
		int status;

	pid = fork();
	if (pid == -1)
		return (1);
	else if (pid == 0)
	{
		execve(ast->args[0], ast->args, NULL);
		exit(1);
	}
	else
	{
		waitpid(pid, &status, 0);
		mini->exit_status = WEXITSTATUS(status);
		return (mini->exit_status);
	}
}