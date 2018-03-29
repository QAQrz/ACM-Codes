#include <bits/stdc++.h>
using namespace std;
char s[128][12];
int i,j,n,k;
int main(){
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)
		scanf("%s",s[i]);
	for(i=n-1;i>n-k-1;i--)
		for(j=0;j<i;j++)
			if(strcmp(s[j],s[j+1])>0)
				swap(s[j],s[j+1]);
	for(i=0;i<n;i++)
		printf("%s\n",s[i]);
	return 0;
}