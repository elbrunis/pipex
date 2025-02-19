#include "pipex.h"

// PATH ES IGUAL A CAMINO
static char	*findpath(char **envp, char *cmd)
{
	int		i;
	char	**lst_path;
	char	*path;
	char	*temp;

    i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == NULL) // buscamos la string que contenga PATH dentro de la variable de entorno
		i++;
	lst_path = ft_split(envp[i] + 5, ':'); // separamos la estring encontrada en substring que seran todos los directorios y ponemos + 5 para omitir lo de
	ft_printf("la columna que se esta imprimiendo es: %d\n", i);
	
    i = 0;
	while (lst_path[i])
	{
		path = ft_strjoin((temp = ft_strjoin(lst_path[i], "/")), cmd); // une la ruta del directorio con el comando para crear la direccion final
		free(temp);
        if (access(path, F_OK) == 0) // verifica si tiene acceso
			return (path);
		i++;
	}

	i = 0;
	while (lst_path[i]) // si no encontramos la ruta no devolvemos nada
		free(lst_path[++i]);
	free(lst_path);
    ft_printf("no se encontro nada colegon\n"); // es temporal
	return (NULL);
}

void execute(char **envp, char *argv)
{
    char **cmd;
    char *path;
    cmd = ft_split(argv, ' ');
    path = findpath(envp, cmd[0]);
    if (!path)
        return;
    if (execve(path, cmd, envp) == -1)
        ft_printf("no se pudo ejecutar el comando\n");

}

// int	main(int argc, char *argv[], char *envp[])
// {
// 	int error;
// 	// char *cmd;

// 	if (argc != 2)
// 		return (error = ft_printf("Error: faltan argumentos\n"));

// 	ft_printf("%s\n", argv[1]);
// 	execute(envp, argv[1]);
// 	return (0);
// }