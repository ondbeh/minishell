/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_heredocs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:45:17 by kmuhlbau          #+#    #+#             */
/*   Updated: 2025/02/03 13:24:26 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

static void	ft_itoa_to_buf(int n, char *buf)
{
	int		i;
	int		len;
	char	tmp;

	if (n == 0)
	{
		buf[0] = '0';
		buf[1] = '\0';
		return ;
	}
	i = 0;
	while (n > 0)
	{
		buf[i++] = (n % 10) + '0';
		n = n / 10;
	}
	buf[i] = '\0';
	len = i;
	while (--len > i / 2)
	{
		tmp = buf[i - len - 1];
		buf[i - len - 1] = buf[len];
		buf[len] = tmp;
	}
}

static char	*create_temp_heredoc_file(int *counter)
{
	char	*temp_path;
	char	*pid_str;
	char	counter_str[32];
	int		fd;

	pid_str = gc_strdup((*get_mini())->identifier);
	ft_itoa_to_buf(*counter, counter_str);
	temp_path = gc_calloc(1, ft_strlen("/tmp/.heredoc_") + ft_strlen(pid_str)
			+ ft_strlen(counter_str) + 2);
	if (!temp_path)
		return (NULL);
	ft_strlcpy(temp_path, "/tmp/.heredoc_", ft_strlen("/tmp/.heredoc_") + 1);
	ft_strlcat(temp_path, pid_str, ft_strlen(temp_path) + ft_strlen(pid_str)
		+ 1);
	ft_strlcat(temp_path, "_", ft_strlen(temp_path) + 2);
	ft_strlcat(temp_path, counter_str, ft_strlen(temp_path)
		+ ft_strlen(counter_str) + 1);
	(*counter)++;
	fd = fdc_open_mode(temp_path, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
		return (gc_free(temp_path), NULL);
	fdc_close(fd);
	return (temp_path);
}

// Return 0 if error, 1 if success
static void	append_heredoc(t_heredoc **heredocs, t_heredoc *new_heredoc)
{
	t_heredoc	*current;

	if (!*heredocs)
		*heredocs = new_heredoc;
	else
	{
		current = *heredocs;
		while (current->next)
			current = current->next;
		current->next = new_heredoc;
	}
}

static t_heredoc	*create_heredoc(t_redirection *redir, int *counter)
{
	t_heredoc	*new_heredoc;

	new_heredoc = gc_calloc(1, sizeof(t_heredoc));
	new_heredoc->delimiter = gc_strdup(redir->file);
	new_heredoc->temp_file = create_temp_heredoc_file(counter);
	new_heredoc->processed = 0;
	new_heredoc->next = NULL;
	return (new_heredoc);
}

int	collect_heredocs_from_node(t_ast_node *node, t_heredoc **heredocs,
		int *counter)
{
	t_redirection	*redir;
	t_heredoc		*new_heredoc;

	if (!node)
		return (1);
	if (!collect_heredocs_from_node(node->left, heredocs, counter))
		return (0);
	if (!collect_heredocs_from_node(node->right, heredocs, counter))
		return (0);
	redir = node->redirections_in;
	while (redir)
	{
		if (redir->type == REDIRECT_HERE_DOC)
		{
			new_heredoc = create_heredoc(redir, counter);
			if (!new_heredoc)
				return (0);
			append_heredoc(heredocs, new_heredoc);
		}
		redir = redir->next;
	}
	return (1);
}
