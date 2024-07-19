#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(){
// copy file1(fd1) into file2(fd2)
// open file 1 in read only mode.
int fd1 = open("a.txt",O_RDONLY);
//if file2 doesnt exist, create it. Open it in write only mode.
//Give read and write permissions to the user to allow reading of file2 to verify its contents and delete the file to repeat the experiment.
int fd2 = open("b.txt",O_CREAT|O_WRONLY, S_IRUSR|S_IWUSR);
char buff[10];
read(fd1, buff, 5);
write(fd2, buff, 5);
close(fd1);
close(fd2);
return 0;
}
