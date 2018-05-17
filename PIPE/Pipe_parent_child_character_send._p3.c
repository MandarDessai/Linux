#include"header.h"
main()
{

int p[2];
pipe(p);
perror("pipe");

if(fork()==0)
{
//child
char k[10],ch;
printf("In child before reading...\n");
read(p[0],k,sizeof(k));
ch=k[0];
printf("character=%c\n",ch);
}
else
{
//parent
char s[10];
printf("In parent before taking input...\n");
printf("Enter the character..\n");
scanf("%s",s);
write(p[1],s,strlen(s)+1);

}



}