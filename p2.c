#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>



#define SIZE 64 // define size
// P2
int main(int argc, char const *argv[])
{
    int fd;
    int count=0; // initialize a counter
    unsigned char buff[SIZE];

    mkfifo("mynamedpipe", S_IRUSR | S_IWUSR); // make same named pipe with user permission

    fd = open("mynamedpipe", O_RDONLY); // open the named pipe
    read(fd, buff, 64);
    printf("from P1: %s\n", buff); //print the data that received

    while(buff[count] != '\n') // condition and loop for finding the length of the string
    {
        count++;
    }

    printf("the length of the string recieved is: %d\n",count); // printing the length
    close(fd);
    return 0;
}