/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 01:57:52 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/19 18:07:28 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "custom_builtins.h"
#include "minishell.h"
#include "struct.h"
#include <unistd.h>

#define PATH_MAX 4096

static int	update_pwd(t_minishell *minishell, char *cwd)
{
	if (minishell->old_pwd)
		gc_free(minishell->old_pwd);
	minishell->old_pwd = minishell->pwd;
	minishell->pwd = gc_strdup(cwd);
	env_set(minishell, "PWD", minishell->pwd);
	return (0);
}

int	builtin_cd(t_minishell *minishell, char **args)
{
	char	*path;
	char	cwd[PATH_MAX];

	if (!args[1])
		path = gc_strdup(get_env_value("HOME", minishell->env_list));
	else if (args[1][0] == '-')
		if (minishell->old_pwd)
		{
			path = minishell->old_pwd;
			printf("%s\n", path);
		}
		else
			printf("cd: OLDPWD not set\n");
	else
		path = args[1];
	if (chdir(path) == -1)
	{
		perror("cd");
		return (1);
	}
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("cd");
		return (1);
	}
	return (update_pwd(minishell, cwd));
}
