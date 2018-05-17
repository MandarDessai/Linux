#include"header.h"
main()
{

int *p;
int id;

id=shmget(4,50,0664);
if(id<0)
{
perror("shmget");
return 0;
}

printf("id=%d\n",id);
p=shmat(id,0,0);
printf("%d\n",p);

shmdt(p);
}