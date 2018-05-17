#include"header.h"
main()
{

char s[20],a[20],b[20];
int fd,fd2,fd3,i;

mkfifo("f1",0664);

fd=open("f1",O_WRONLY|0664);
if(fd<0)
{
perror("open");
return 0;
}

printf("Enter the data..\n");
scanf("%s",s);

write(fd,s,strlen(s)+1);

////////////////////////////

fd2=open("f2",O_RDONLY|0664);
if(fd2<0)
{
perror("open");
return 0;
}

fd3=open("f3",O_RDONLY|0664);
if(fd3<0)
{
perror("open");
return 0;
}

read(fd2,a,sizeof(a));
read(fd3,b,sizeof(b));

printf("Back in process 1...\n");
printf("\n\nSorted Numbers:");
for(i=0;a[i];i++)
printf("%c ",a[i]);

printf("\n");

printf(sorted characters:");
for(i=0;b[i];i++)
printf("%c ",b[i]);

}