#include <bits/stdc++.h>
using namespace std;
char s[1024],ans[1024][128];
int n,l,i,j;
int main(){
	scanf("%d\n",&n);
	gets(s);
	l=strlen(s);
	for(i=0;i<l;i++)
		ans[i/n][i%n]=s[i];
	for(j=0;j<n;j++){
		for(i=(l-1)/n;~i;i--)
			printf("%c",ans[i][j]?ans[i][j]:' ');
		printf("\n");
	}
	return 0;
}