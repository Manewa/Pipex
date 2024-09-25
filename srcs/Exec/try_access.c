#include "../../includes/pipex.h"

void	last_process(t_data *data, list *cmd, int *pipefd)
{
	if (dup2(data->output_fd, STDOUT_FILENO) < 0)
	{
		ft_printf("Error : %s\n", strerror(errno));
		ft_free_both(data, cmd);
	}
	close(pipefd[1]);	
}

void	first_process(t_data *data, list *cmd, int *pipefd)
{
	if (dup2(data->input_fd, STDIN_FILENO) < 0)
	{
		ft_printf("Error : %s\n", strerror(errno));
		ft_free_both(data, cmd);
	}
	close(pipefd[0]);
}
