#include"header.h"
main()
{

int *p,*p2;
int id,n,id2;
int sum=0,n,k,i=0,j=0,m[20],l,x; 

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

/////reversing the number now

k=n;
while(k>0)
{
m[i]=k%10;
k=k/10;
i++;
}

for(j=0,l=i;j<i;j++,l--)
{
x=l;
while(x>1)
{
m[j]=m[j]*10;
x--;
}
sum=sum+m[j];
}
printf("sum=%d\n",sum);

//////reversed number in sum

id2=shmget(4,50,IPC_CREAT|0664);
if(id2<0)
{
perror("shmget");
return 0;
}

p2=shmget(id2,0,0);
p2=&sum;

shmdt(p2);
}