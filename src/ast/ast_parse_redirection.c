/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_parse_redirection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:15:00 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/11 10:55:35 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static t_redirection_type	get_redirection_type(t_token_type token)
{
	if (token == TOKEN_REDIRECT_IN)
		return (REDIRECT_IN);
	if (token == TOKEN_REDIRECT_OUT)
		return (REDIRECT_OUT);
	if (token == TOKEN_REDIRECT_OUT_APPEND)
		return (REDIRECT_OUT_APPEND);
	return (REDIRECT_HERE_DOC);
}

t_redirection	*parse_redirection(t_token_type **tokens, char ***instructions)
{
	t_redirection	*redirection;

	redirection = gc_calloc(1, sizeof(t_redirection));
	redirection->type = get_redirection_type(**tokens);
	++(*tokens);
	++(*instructions);
	if (!*tokens || **tokens != TOKEN_COMMAND)
	{
		gc_free(redirection);
		return (NULL);
	}
	redirection->file = **instructions;
	++(*tokens);
	++(*instructions);
	return (redirection);
}
