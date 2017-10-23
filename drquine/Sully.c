#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
int i=5;
if(i<=0)return 1;char b[1024];if(!strstr(__FILE__,"Sully.c"))i--;sprintf(b,"Sully_%d.c",i);FILE *fp=fopen(b,"w");if(fp==NULL)return 0;
char *c="#include <stdio.h>%1$c#include <stdlib.h>%1$c#include <string.h>%1$cint main(){%1$cint i=%2$d;%1$cif(i<=0)return 1;char b[1024];if(!strstr(__FILE__,%3$cSully.c%3$c))i--;sprintf(b,%3$cSully_%%d.c%3$c,i);FILE *fp=fopen(b,%3$cw%3$c);if(fp==NULL)return 0;%1$cchar *c=%3$c%4$s%3$c;%1$cfprintf(fp,c,10,i,34,c);fclose(fp);char b2[1024];sprintf(b2,%3$cclang -Wall -Wextra -Werror -o %%.*s %%s%3$c,(int)strlen(b)-2, b, b);system(b2);sprintf(b2,%3$c./%%.*s%3$c,(int)strlen(b)-2, b);system(b2);%1$c}%1$c";
fprintf(fp,c,10,i,34,c);fclose(fp);char b2[1024];sprintf(b2,"clang -Wall -Wextra -Werror -o %.*s %s",(int)strlen(b)-2, b, b);system(b2);sprintf(b2,"./%.*s",(int)strlen(b)-2, b);system(b2);
}
