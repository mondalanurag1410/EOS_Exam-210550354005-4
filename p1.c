#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>



// P1
int main()
{
    int fd; // make  a file descriptor

    mkfifo("mynamedpipe", S_IRUSR | S_IWUSR); // make a fifo (named pipe) with user permission

    fd = open("mynamedpipe", O_WRONLY); // open the named pipe
    write(fd, "my exam code\n", 13); // write on the named pipe
    close(fd);
    return 0;
}