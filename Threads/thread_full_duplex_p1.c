#include"header.h"
void *thread(void*p)
{
int fd;
char s[20]
mkfifo("f1",0664);

fd=open("f1",O_CREAT|O_WRONLY|0664);
while(1)
{
printf("Enter data\n");
scanf("%s",s);
write(fd,s,strlen(s)+1);
}
}

void *thread_2 (void *p)
{

int fd;
char s[20];
fd=open("f2",0664);

while(1)
{
read(fd,s,sizeof(s));
printf("data=%s\n",s);
}

pthread_exit(0);
}

main()
{

pthread_t t1,t2;

pthread-create(&t1,0,thread_1,0);
pthread-create(&t2,0,thread_2,0);

}