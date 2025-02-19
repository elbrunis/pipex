int main(int argc, char *argv[])
{
    int std[2];
    int p_fd[2];  // Pipe
    pid_t pid1;
    int file_in, file_out;

    std[0] = STDIN_FILENO;
    std[1] = STDOUT_FILENO;

    if (argc != 3)
        return 1;
    pipe(p_fd);
    pid1 = fork();

    if (pid1 == 0) 
    {
        printf("Soy el proceso hijo: %i y mi padre es: %i\n", getpid(), getppid());

        file_out = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777);
        close(p_fd[1]);
        dup2(p_fd[0], STDIN_FILENO);
        // close(p_fd[0]);

        dup2(file_out, STDOUT_FILENO);
        // close(file_out);
        printf("hola buenas tardes\n");
        execlp("grep", "grep", "esta", NULL);
        return 1;
    } 
    else 
    {
        printf("Soy el proceso padre: %i y mi hijo es: %i\n", getpid(), pid1);

        file_in = open(argv[1], O_RDONLY);

        close(p_fd[0]);
        dup2(p_fd[1], STDOUT_FILENO);
        // close(p_fd[1]);

        dup2(file_in, STDIN_FILENO);
        // close(file_in);
        execlp("cat", "cat", NULL);
        return 1;
    }
    return 0;
}