#include <stdio.h>
/*
	Grace
*/
#define FIRST
#define SECOND
#define FT(x)int main(){FILE *fp=fopen("Grace_kid.c","w+");char *c="#include <stdio.h>%c/*%c%cGrace%c*/%c#define FIRST%c#define SECOND%c#define FT(x)int main(){FILE *fp=fopen(%cGrace_kid.c%c,%cw+%c);char *c=%c%s%c;fprintf(fp,c,10,10,9,10,10,10,10,34,34,34,34,34,c,34,10,10);fclose(fp);}%cFT(1)%c";fprintf(fp,c,10,10,9,10,10,10,10,34,34,34,34,34,c,34,10,10);fclose(fp);}
FT(1)
