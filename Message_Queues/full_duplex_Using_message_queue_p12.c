#include"header.h"
struct msgbuf
{
int mtype;
char data_send[30];
};

main(int argv,char **argc)
{

int id[2];
char s[20];
struct msgbuf v[2];

if(argv!=3)
{
printf("Usage: ./a.out mtype_rec mtype_send\n");
return 0;
}

id[0]=msgget(4,IPC_CREAt|0664);
if(id[0]<0)
{
perror("msgget");
return 0;
}

printf("id[0]=%d\n",id[0]);
msgrcv(id,&v[0],atoi(argc[1]),0);
perror("msgrcv");

strcpy(s,v[0].data_send);
printf("data=%s\n",s);

//////////////////////////////////////////// data recieved from process 1

id[1]=msgget(4,IPC_CREAT|0664);
if(id[1]<0)
{
perror("msgget");
return 0;
}

printf("Enter the data to send to process 1..\n");
gets(s);

printf("id[1]=%d\n",id[1]);
v[1].mtype=atoi(argc[2]);
strcpy(v[1].data_send,s);

strsnd(id[1],&v[1],strlen(v[1].data_send)+1,0);
perror("msgsnd");


}