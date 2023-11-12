#include "minishell.h"

// check if eof
// check if cmd after eof
// set a bool to heredoc done
// can the input be NULL
void get_heredoc(t_list_pre *current, t_parsing *bag)
{
	char	*delimiter;

	if (check_redir(current->pre_tokken) == HEREDOC && bag->heredoc_flag)
		ft_error(SYNTAX, bag);
	delimiter = current->next->pre_tokken;
	if (!delimiter)
		write(STDERR_FILENO, "syntax error near unexpected token `newline'", 44);
	ft_t_lstlast(bag->t_head)->heredoc = get_heredoc_input(delimiter, bag);
	bag->heredoc_flag = TRUE;
}

char *get_heredoc_input(char *delimiter, t_parsing *bag)
{
	char	*heredoc;
	char	*input;
	char	*to_free;

	while (TRUE)
	{
		write(1, "> ", 2);
		input = get_next_line(0);
		if (endoffile(input, delimiter))
			break ;
		to_free = heredoc;
		heredoc = ft_strjoin(heredoc, input);
		if (!heredoc)
			ft_error(MEMORY, bag);
		free(to_free);
		free(input);
	}
	return (heredoc);
}

unsigned int endoffile(char *input, char *delimiter)
{
	if (!input)
	{
		write_missing(delimiter);
		return (TRUE);
	}
	if (is_eof(input, delimiter))
	{
		free(input);
		return (TRUE);
	}
	return (FALSE);
}

bool is_eof(char *input, char *delimiter)
{
	int		delimiter_len;

	delimiter_len = ft_strlen(delimiter);
	return ((bool)(ft_strncmp(input, delimiter, delimiter_len) == 0
				   && input[delimiter_len] == '\n'
				   && ft_strlen(input) == delimiter_len + 1));
}

void write_missing(char *delimiter)
{
	int deli_size;

	deli_size = ft_strlen(delimiter);
	write(STDERR_FILENO, "\nminishell: warning: here-document delimited by end-of-file (wanted `", 69);
	write(STDERR_FILENO, &delimiter, deli_size);
	write(STDERR_FILENO, "')\n", 3);
}
