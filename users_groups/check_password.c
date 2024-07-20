
// ATTENTION!!!
// RUN THIS PROGRAM AT YOUR OWN RISK! THE ENTERED PASSWORD IS NOT REMOVED FROM THE MEMORY UNTIL THE PROGRAM TERMINATES.
// ATTENTION!!!

// Run as superuser if error is thrown.
#include <pwd.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <shadow.h>
int
main(int argc, char *argv[])
{
    char *password, *encrypted;
    int authOk, len;
    char username[40];
    struct passwd *pwd;
    struct spwd *spwd;
    printf("Username: ");
    scanf("%s",username);

    // get record from /etc/passwd file corresponding to username
    pwd = getpwnam(username);
    // collect password from user
    password = getpass("Password: ");
    // check if password in the entry is 'x'. If yes, we need to refer too /etc/shadow to get the password.
    if(strlen(pwd->pw_passwd)==1 && pwd->pw_passwd[0]=='x'){
	spwd = getspnam(username);
	pwd->pw_passwd = spwd->sp_pwdp;}

    // obtain the encrypted form of the entered password.
    encrypted = crypt(password, pwd->pw_passwd);
    // compare the encrypted forms of the passwords and check
    authOk = strcmp(encrypted, pwd->pw_passwd) == 0;
    if (!authOk) 
        printf("Incorrect password\n");
    else
    printf("Successfully authenticated: UID=%ld\n", (long) pwd->pw_uid);

}
