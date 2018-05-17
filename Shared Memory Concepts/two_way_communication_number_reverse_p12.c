#include"header.h"
main()
{

int *p,*p2;
int id,id2;

id=shmget(4,50,IPC_CREAT|0664);
if(id<0)
{
perror("shmget");
return 0;
}

printf("id=%d\n",id);
p=shmat(id,0,0);

printf("Enter the data..\n");
scanf("%d",&p);
shmdt(p);

//////////////// taking the reversd number

id2=shmget(4,50,0664);
if(id2<0)
{
perror("shmget");
return 0;
}

p2=shmat(at,0,0);

printf("reversed number=%d\n",p2);
shmdt(p2);
}