#include"header.h"
main()
{

int p[2];
pipe(p);
perror("pipe");

if(fork()==0)
{
//child
char k[10];
int n;
printf("In child before taking reading...\n");
read(p[0],&k,sizeof(k));
n=atoi(k);
printf("data from parent is %d\n",n);
}
else
{
//parent
char s[10];
printf("In parent.....\n");
printf("Enter an integer....\n");
scanf("%s",s);
write(p[1],s,strlen(s)+1);
}

}