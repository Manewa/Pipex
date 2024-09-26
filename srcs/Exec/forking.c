#include "../../includes/pipex.h"

void	fork_n_pipe(t_data *data, list *cmd, char **envp)
{
	int		pipefd[2];
	int		pid;
	list	*tmp;

	tmp = cmd;
	while (cmd)
	{
		if (pipe(pipefd) == -1)
			ft_free_both(data, cmd);
		pid = fork();
		if (pid < 0)
			ft_free_both(data, cmd);
		cmd = cmd->next;
		if (pid == 0)
		{
			first_process(data, cmd, pipefd, data->input_fd);
			last_process(data, cmd, pipefd, data->output_fd);
		}
		else
		{
			close(pipefd[1]);
			dup2(pipefd[0], STDIN_FILENO);
			close(pipefd[0]);
		}
		cmd = cmd->next;
	}
	cmd = tmp;
	tmp = tmp->next;
	if (execve(tmp->pathcmd, tmp->cmd_flag, envp) == -1)
	{
		ft_printf("Error : %s\n", strerror(errno));
		ft_free_both(data, cmd);
	}
}
