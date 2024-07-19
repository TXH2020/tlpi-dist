#include <sys/stat.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int
main(int argc, char *argv[])
{
    int fd;
    struct iovec iov[3];
#define STR_SIZE 5
    char str1[STR_SIZE];         /* First buffer */
    char str2[STR_SIZE];	 /* Second buffer */
    char str3[STR_SIZE];	 /* Third buffer */
    ssize_t numRead, totRequired;

    fd = open(argv[1], O_RDONLY);

    totRequired = 15;

    iov[0].iov_base = str1;
    iov[0].iov_len = STR_SIZE;

    iov[1].iov_base = str2;
    iov[1].iov_len = STR_SIZE;

    iov[2].iov_base = str3;
    iov[2].iov_len = STR_SIZE;

    numRead = readv(fd, iov, 3);

    if (numRead < totRequired)
        printf("Read fewer bytes than requested\n");

    printf("total bytes requested: %ld; bytes read: %ld\n",
            (long) totRequired, (long) numRead);
    printf("Buffer1=%s\n",str1);
    printf("Buffer2=%s\n",str2);
    printf("Buffer3=%s\n",str3);
    close(fd);
    return 0;        
}
