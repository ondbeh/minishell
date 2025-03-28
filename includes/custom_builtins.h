/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_builtins.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:31:53 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/20 16:20:07 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUSTOM_BUILTINS_H
# define CUSTOM_BUILTINS_H

# include "env.h"
# include "utils.h"
# include "wrapper.h"
# include <libft.h>
# include <stdio.h>
# include <unistd.h>

int		builtin_echo(char **args);
int		builtin_env(t_list *env_list);
int		builtin_pwd(t_minishell *minishell);
int		builtin_cd(t_minishell *minishell, char **args);
void	builtin_exit(t_minishell *minishell, char **args);
int		builtin_export(t_minishell *minishell, char **args);
int		builtin_unset(t_minishell *minishell, t_ast_node *ast);
int		print_invalid_identifier(char *cmd, char *arg, t_minishell *mini);
int		print_invalid_option(char *cmd, char *arg, t_minishell *mini);
int		command_not_found(t_minishell *mini, t_ast_node *ast);

#endif
