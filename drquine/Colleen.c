#include <stdio.h>
void function(){char *c="#include <stdio.h>%cvoid function(){char *c=%c%s%c;printf(c,10,34,c,34,10,10,9,10,10,10,10,9,10,10,10);}%c/*%c%ccomment1%c*/%cint main(){%c/*%c%ccomment2%c*/%cfunction();}%c";printf(c,10,34,c,34,10,10,9,10,10,10,10,9,10,10,10);}
/*
	comment1
*/
int main(){
/*
	comment2
*/
function();}
