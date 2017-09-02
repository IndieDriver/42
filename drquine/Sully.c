#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
int i=5;
if(i==0)return 1;char b[1024];sprintf(b,"Sully_%d.c",i);i--;FILE *fp=fopen(b,"w+");char *c="#include <stdio.h>%c#include <stdlib.h>%c#include <string.h>%cint main(){%cint i=%d;%cif(i==0)return 1;char b[1024];sprintf(b,%cSully_%%d.c%c,i);i--;FILE *fp=fopen(b,%cw+%c);char *c=%c%s%c;fprintf(fp,c,10,10,10,10,i,10,34,34,34,34,34,c,34,34,34,34,34,10);fclose(fp);char b2[1024];sprintf(b2,%cclang -Wall -Wextra -Werror -o %%.*s %%s%c,(int)strlen(b)-2, b, b);system(b2);sprintf(b2,%c./%%.*s%c,(int)strlen(b)-2, b);system(b2);}%c";fprintf(fp,c,10,10,10,10,i,10,34,34,34,34,34,c,34,34,34,34,34,10);fclose(fp);char b2[1024];sprintf(b2, "clang -Wall -Wextra -Werror -o %.*s %s",(int)strlen(b)-2, b, b);system(b2);sprintf(b2, "./%.*s",(int)strlen(b)-2, b);system(b2);}
