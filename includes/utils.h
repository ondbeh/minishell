/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:19:43 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/07 17:01:25 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "wrapper.h"

void	*gc_strdup(const char *s);
char	*gc_strjoin(char const *s1, char const *s2);
void	cleanup_main(t_minishell *mini);

#endif
