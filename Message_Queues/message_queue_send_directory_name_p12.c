#include"header.h"
struct msgbuf
{
int mtype;
char data[250];
}

main(int argv,char **argc)
{

int id,count=0,i=0;
struct msgbuf v;
char filename[100];
DIR *dirp;
struct dirent *direntp;

if(argv!=2)
{
printf("Usage:./a.out mtype\n");
return 0;
}

id=msgget(5,IPC_CREAT|0664);
if(id<0)
{
perror("msgget");
return 0;
}

printf("id=%d\n",id);
msgrcv(id,&v,atoi(argc[1]),0);
printf("path=%s\",v.data);

//////////////////// message ie the path is recieved and now the second part ie counting the number of folders will be done


if((dirp=opendir(v.data))==NULL)
{
perror("failed to open directory");
return 0;
}


while((dirent=readdir(dirp))!=NULL)
{
printf("filename=%s\n",dirent->d_name);
count=count+1;
}

printf("Number of files=%d\n",count);

}