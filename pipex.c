
#include "pipex.h"

static void proces(int *pfd_close, int *pfd, char *addres, int std1, int std2, int i)
{
    int file;

    if (i == 0)
        file = open(addres, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    else
        file = open(addres, O_RDONLY);
    close(*pfd_close);
    dup2(*pfd, std1);
    close(*pfd);
    dup2(file, std2);
    close(file);
}
// execute(char **envp, char *argv)

int main(int argc, char *argv[], char **envp)
{
    int p_fd[2];  // Pipe
    pid_t pid1;

    if (argc != 5)
        ft_printf("Error: faltan argumentos\n");
    pipe(p_fd);
    pid1 = fork();

    if(pid1 == 0)
    {
        proces(&p_fd[1], &p_fd[0], argv[4], STDIN_FILENO, STDOUT_FILENO, 0); //child proces
        ft_printf("hola\n");
        execute(envp, argv[3]);
    }
    else
    {
        proces(&p_fd[0], &p_fd[1], argv[1], STDOUT_FILENO, STDIN_FILENO, 1); //parent proces
        execute(envp, argv[2]);
    }
    
}