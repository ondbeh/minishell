/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:19:43 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/03 13:23:43 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "enums.h"
# include "struct.h"
# include "wrapper.h"
# include <readline/history.h>
# include <readline/readline.h>

void		*gc_strdup(const char *s);
char		*gc_strjoin(char const *s1, char const *s2);
char		*gc_strjoin_three(char const *s1, char const *s2, char const *s3);
char		*gc_substr(char const *s, unsigned int start, size_t len);
char		**gc_split(char const *s);
char		**gc_split_at(char const *s, char c);
void		gc_split_free(char ***split);
int			is_redirection_in(t_token_type tokens);
int			is_redirection_out(t_token_type tokens);
int			is_redirection(t_token_type tokens);
char		*gc_itoa(int n);
void		append_char(char **dest, char c);
void		append_string(char **dest, const char *src);
char		*gc_unsplit(char **split);
int			gc_split_size(char **split);
t_minishell	**get_mini(void);
char		*get_user_input(char *prompt);
int			matches_pattern(const char *pattern, const char *string);
int			remove_quotes(char **str);
void		handle_transform_operator(char *line, char *mod_line, int *i,
				int *j);
void		handle_transform_special_token(char *line, char *mod_line, int *i,
				int *j);
void		handle_transform_quotes(char *line, char *mod_line, int *i, int *j);
char		*generate_unique_identifier(void);
#endif
