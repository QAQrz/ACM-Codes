#include <bits/stdc++.h>
using namespace std;
int n,cnt,a[33],t;
void dfs(int x,int a[],int s,int m){
	a[s++]=x;
	if(!m){
		cout<<n<<"=";
		for(int i=0;i<s;i++)
			printf("%d%c",a[i],i<s-1?'+':++t%4?';':'\n');
		return;
	}
	for(int i=x;i<=m-i;i++)
		dfs(i,a,s,m-i);
	dfs(m,a,s,0);
}
int main(){
	cin>>n;
	for(int i=1;i<=n-i;i++)
		dfs(i,a,0,n-i);
	printf("%d=%d\n",n,n);
	return 0;
}