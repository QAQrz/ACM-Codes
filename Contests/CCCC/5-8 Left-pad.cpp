#include <bits/stdc++.h>
using namespace std;
char s[55],str[111111];
int n,i,l;
int main(){
	scanf("%d %s\n",&n,s);
	gets(str);
	l=strlen(str);
	for(i=l;i<n;i++)
		cout<<s[0];
	for(i=max(l-n,0);i<l;i++)
		cout<<str[i];
	cout<<endl;
	return 0;
}