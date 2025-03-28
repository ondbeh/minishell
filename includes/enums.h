/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:48:07 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/02 11:58:33 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

typedef enum e_token_type
{
	TOKEN_EMPTY,
	TOKEN_AND,
	TOKEN_OR,
	TOKEN_PIPE,
	TOKEN_REDIRECT_IN,
	TOKEN_REDIRECT_OUT,
	TOKEN_REDIRECT_OUT_APPEND,
	TOKEN_REDIRECT_HERE_DOC,
	TOKEN_PAREN_OPEN,
	TOKEN_PAREN_CLOSE,
	TOKEN_COMMAND
}	t_token_type;

typedef enum e_redirection_type
{
	REDIRECT_IN,
	REDIRECT_OUT,
	REDIRECT_OUT_APPEND,
	REDIRECT_HERE_DOC
}	t_redirection_type;

typedef enum e_builtin_type
{
	BUILTIN_NONE,
	BUILTIN_ECHO,
	BUILTIN_CD,
	BUILTIN_PWD,
	BUILTIN_EXPORT,
	BUILTIN_UNSET,
	BUILTIN_ENV,
	BUILTIN_EXIT
}	t_builtin_type;

typedef enum e_malloc_source
{
	MALLOC_AST,
	MALLOC_ENV,
	MALLOC_EXEC,
	MALLOC_GC,
	MALLOC_HEREDOC,
	MALLOC_PARSER,
	MALLOC_TOKENIZER,
	MALLOC_UTILS,
	MALLOC_WRAPPER,
	MALLOC_UNDEFINED
}	t_malloc_source;

#endif
