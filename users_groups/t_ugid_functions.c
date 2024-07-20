#include <stdio.h>
#include "ugid_functions.h"
int main(){
printf("%s\n",userNameFromId(0));
printf("%ld\n",userIdFromName("root"));
printf("%s\n",groupNameFromId(0));
printf("%ld\n",groupIdFromName("root"));
return 0;
}
