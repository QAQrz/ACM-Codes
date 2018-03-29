#include <stdio.h>
#include <ctype.h>
char s[22];
int main(){
	scanf("%s",s);
	for(int i=0;s[i];i++)
		printf("%c",isdigit(s[i])?'$':s[i]);
	printf("\n");
	return 0;
}