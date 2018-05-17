#include"header.h"
struct msgbuf
{
int mtype;
char data[250];
};

main(int argv,char **argc)
{

int id;
char path[250];
struct msgbuf v;

if(argc!=2)
{
printf("Usage:./a.out m_type_number\n");
return 0;
}

getcwd(path,250);  //helps you get the current working directory add in the path 

id=msgget(5,IPC_CREAT|0664);
if(id<0)
{
perror("msgget");
return 0;
}

printf("id=%d\n",id);
printf("Path=%s\n",path);

v.mtype=atoi(argc[1]);
strcpy(v.data,path);

printf("v.data=%s\n",v.data);
msgsnd(id,&v,strlen(v.data)+1,0);
perror("msgsnd");

}