#include "../../headers/minishell.h"

extern volatile sig_atomic_t g_status;

void	handle_sigtstp(int signum)
{
	if (signum == SIGINT)
	{
		g_status = 130;
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}

void	handle_signal(t_parsing *bag)
{
	(void)bag;
	struct sigaction sa;
	sa.sa_handler = &handle_sigtstp;
	sigaction(SIGINT, &sa, NULL);
	sa.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sa, NULL);
}
