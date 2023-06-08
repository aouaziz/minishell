#include "../../includes/minishell.h"


void    init_strcut(t_shell *shell, t_exe *exe)
{
    int i;

    i = 0;
    exe->size = ft_lstsize_s(shell);

    if (exe->size > 1)
    {
        exe->tube = (int **)malloc(sizeof(int *) * (exe->size - 1));
        if (!exe->tube)
            return (ftt_print_fd(2, "can't allocate pipes\n"), exit (1));
        i = 0;
        while (i < exe->size)
        {
            exe->tube[i] =(int *) malloc(sizeof(int) * 2);
            if (!exe->tube[i])
            return (ftt_print_fd(2, "can't allocate each pipe\n"), exit(1));
            i++;
        }
        i = 0;
        while (i < exe->size)
        {
            if (pipe(exe->tube[i]) == -1)
                return (ftt_print_fd(2, "pipe pb\n"),exit (1));
            i++;
        }
    }
}

void    executing(t_shell *shell)
{
    t_exe exe;
    pid_t fid;

    init_strcut(shell, &exe);
    fid = pipe_and_fork(shell, &exe);
    if (fid == -1)
        ftt_print_fd();

}