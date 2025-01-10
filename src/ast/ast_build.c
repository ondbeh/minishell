/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:19:53 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/10 13:55:22 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"


t_ast_node	*ast_build(t_token_type *tokens, char **split_line)
{
	t_ast_node	*node;

	if (!tokens)
		return (NULL);
	node = parse_logical_ops(&tokens, &split_line);
	if (!node)
	{
		ft_putstr_fd("bash: syntax error near unexpected token `", 2);
		ft_putstr_fd(*split_line, 2);
		ft_putstr_fd("'\n", 2);
	}
	return (node);
}
