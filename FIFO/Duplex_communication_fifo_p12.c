#include"header.h"
main()
{


char s[20],b[20],a[20],y;
int fd,m=0,i,k=0,l,t,new,n[10],j,new1,e,p=0,fd2,fd3;
//mkfifo("f1",0664);
//perror("mkfifo");

fd=open("f1",O_RDONLY|0664);
  if(fd<0)
  {
   perror("open");
   return 0;
  }


 read(fd,s,sizeof(s));
 printf("data=%s",s);


for(i=0;s[i];i++)
{
  if((s[i]>=65&&s[i]<=90)||(s[i]>=97&&s[i]<=122))
   {
    b[k]=s[i];
    k=k+1;
    p=k;
   }
  else
   {
    a[m]=s[i];
    m=m+1;
   }
}
a[m]='\n';
b[k]='\n';

for(i=0;a[i];i++)
printf("%c ",a[i]);

for(i=0;b[i];i++)
printf("%c",b[i]);


printf("----------\n");
printf("character data:");

for(l=0;l<=k-1;l++)
{
printf("%c",b[l]);
}
printf("------------\n");

l=atoi(a);

printf("--------------\n");
printf("number data=%d\n",l);

i=0;
new=l;
while(new>0)
{
//sort the number using % and / operator
new1=new%10;
n[i++]=new1;
new=new/10;
}
/////////////////////
j=i;
i=0;
while(i<j)
{
printf("diff nos=%d\n",n[i++]);
}
////////////////////
i=0;
k=j;
j=0;
for(i=0;i<k;i++)
 for(j=i+1;j<k;j++)
 {
  if(n[i]>n[j])
  {
   e=n[i];
   n[i]=n[j];
   n[j]=e;
  }
 }
i=0;
while(i<k)
{
printf("sorted nos=%d\n",n[i++]);
}
//////////////////////// sorted array of numbers in in n[i](ascending),count=k
i=0;
j=0;

for(i=0;i<p;i++)
 {
  for(j=i+1;j<p;j++)
   {
    if(b[j]>b[i])
     {
      y=b[i];
      b[i]=b[j];
      b[j]=y;
     }
   }
 }

i=0;
while(i<p)
printf("sorted letters=%c\n",b[i++]);
/////////////////////////////////////// sorted char=b[i],count=p

//number string=a[i],count=k

//mkfifo("f2",0664);
fd2=open("f2",O_WRONLY|0664);
 if(fd<0)
 {
  perror("open");
  return 0;
 }

//mkfifo("f3",0664);
fd3=open("f3",O_WRONLY|0664);
if(fd<0)
{
perror("open");
return 0;
}

write(fd2,a,strlen(a)+1);
write(fd3,b,strlen(b)+1);

}