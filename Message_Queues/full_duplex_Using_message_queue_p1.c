#include"header.h"
struct msgbuf
{
int mtype;
char data_send[30];
};

main(int argv,char **argc)
{

int id[2];
char s[30];
struct msgbuf v[2];

if(argv!=3)
{
printf("Usage: ./a.out mtype_send mtype-recieve\n");
return 0;
}

id[0]=msgget(4,IPC_CREAT|0664);

printf("In the process 1...\n");
printf("Enter the message\n");
scanf("%s",s);

v[0].mtype=atoi(argc[1]);
strcpy(v[0].data_send,s);

msgsnd(id,&v[0],strlen(v[0].data)+1,0);
perror("msgsnd");

//////////////////////////////// 

id[1]=msgget(4,IPC_CREAT|0664);
if(id[1]<0)
{
perror("msgget");
return 0;
}

printf("process 1 recieving...\n");
printf("id[1]=%d\n",id[1]);

msgrcv(id[1],&v[1],atoi(argc[2]),0);
perror("msgrcv");

printf("Message=%s\n",v[1].data_send);

}