/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:36:20 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/10 16:34:27 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	is_own_builtin(char *command, char **args)
{
	(void)args;
	(void)command;
	// Not implemented yet
	// if (ft_strncmp(command, "cd", 2) == 0)
	// 	return (1);
	// if (ft_strncmp(command, "echo", 4) == 0)
	// 	return (1);
	// if (ft_strncmp(command, "env", 3) == 0)
	// 	return (1);
	// if (ft_strncmp(command, "exit", 4) == 0)
	// 	return (1);
	// if (ft_strncmp(command, "export", 6) == 0)
	// 	return (1);
	// if (ft_strncmp(command, "pwd", 3) == 0)
	// 	return (1);
	// if (ft_strncmp(command, "unset", 5) == 0)
	// 	return (1);
	return (0);
}

char	*get_command_path(char *command, t_list *env_list)
{
	char	**path;
	char	*env_path;
	char	*command_path;
	int		i;
	char	*tmp;

	env_path = get_env_value("PATH", env_list);
	if (!env_path)
		return (NULL);
	printf("1\n");
	path = gc_split_at(env_path, ':');
	printf("2\n");
	i = 0;
	while (path[i])
	{
		printf("path[i]: %s\n", path[i]);
		tmp = gc_strjoin(path[i], "/");
		command_path = gc_strjoin(tmp, command);
		printf("command_path: %s\n", command_path);
		gc_free(tmp);
		if (access(command_path, F_OK) == 0)
			return (gc_split_free(&path), command_path);
		gc_free(command_path);
		i++;
	}
	gc_split_free(&path);
	return (NULL);
}
