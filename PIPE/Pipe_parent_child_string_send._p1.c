#include"header.h"
main()
{

int p[2];
pipe(p);
perror("pipe");

if(fork()==0)
{
 //child
char s[20];
printf("In child before reading...\n");
read(p[0],s,sizeof(s));
printf("In child givng output=%s\n",s);
}
else
{
//parent
char k[20];
printf("In the parent..Enter string..\n");
scanf("%s",k);
write(p[1],k,strlen(k)+1);
}

}