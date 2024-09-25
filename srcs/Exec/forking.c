#include "../../includes/pipex.h"

void	fork_n_pipe(t_data *data, list *cmd, char **envp)
{
	int		pipefd[2];
	int		pid;
	list	*tmp;

	tmp = cmd;
	while (cmd != NULL)
	{
		if (pipe(pipefd) == -1)
			ft_free_both(data, cmd);
		pid = fork();
		if (pid < 0)
			ft_free_both(data, cmd);
		if (pid == 0)
			first_process(data, cmd, pipefd);
		else
		{
			wait(&pid);
			last_process(data, cmd, pipefd);
		}
		if (execve(cmd->pathcmd, cmd->cmd_flag, envp) == -1)
		{
			ft_printf("Error : %s\n", strerror(errno));
			ft_free_both(data, cmd);
		}
		cmd = cmd->next;
	}
	cmd = tmp;
}
