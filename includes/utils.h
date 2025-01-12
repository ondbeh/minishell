/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obehavka <obehavka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:19:43 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/01/12 12:40:52 by obehavka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "enums.h"
# include "struct.h"
# include "wrapper.h"

void	*gc_strdup(const char *s);
char	*gc_strjoin(char const *s1, char const *s2);
char	*gc_substr(char const *s, unsigned int start, size_t len);
char	**gc_split(char const *s);
char	**gc_split_at(char const *s, char c);
void	gc_split_free(char ***split);
int		is_redirection_in(t_token_type tokens);
int		is_redirection_out(t_token_type tokens);
int		is_redirection(t_token_type tokens);

#endif
