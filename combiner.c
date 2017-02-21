#include  <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>


#define   MAX_COUNT  200

void  main(int argc, char **argv)
{
	int status,pid;    
	pid_t pid1;
    pid_t pid2;
    int fd[2];
    pipe(fd);//creating pipe on fd
    pid1 = fork();//creating 1st child process

    if (pid1 == 0)
    {
        dup2(fd[1],1);//duplicating write fd
        close(fd[0]);//closing read file fd
        execlp("./mapper", "mapper",argv[1], NULL);//calling exec to run mapper with filename as argv[1]
    }
    pid2 = fork();//creating child 2
    if (pid2 == 0)
    {
        dup2(fd[0],0);//duplicating read fd
        close(fd[1]);//closing write fd
        execlp("./reducer", "reducer", NULL);//calling exec to run reducer
    }

    close(fd[0]);//closing read fd
    close(fd[1]);//closing write fd
    
}