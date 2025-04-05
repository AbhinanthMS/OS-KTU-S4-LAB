#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<stdlib.h>

struct dirent *dptr;
int main()
{
    char a[30];
    DIR *dirptr;
    printf("enter the path of directory");
    scanf("%s",a);
    dirptr =opendir(a);
    if (dirptr==NULL)
    {
        printf("dir not found");

    
    exit(0);
   }
   else{
    while(dptr=readdir(dirptr))
   
    {
        printf("%s\n",dptr->d_name);

    }
   }closedir(dirptr);
return 0;
}