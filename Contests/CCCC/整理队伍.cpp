#include <bits/stdc++.h>
using namespace std;
int n,a[111],m,x,y;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>m;
	while(m--){
		cin>>x>>y;
		swap(a[x],a[y]);
	}
	for(int i=1;i<=n;i++)
		printf("%d%c",a[i],i<n?' ':'\n');
	return 0;
}