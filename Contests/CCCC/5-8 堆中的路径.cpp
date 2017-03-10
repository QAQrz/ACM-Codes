#include <bits/stdc++.h>
using namespace std;
int n,m,a[1024],i,j,x;
int main(){
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		for(j=i;j>1&&a[j]<a[j/2];j/=2)
			swap(a[j],a[j/2]);
	}
	while(m--){
		cin>>x;
		while(x){
			printf("%d%c",a[x],x>1?' ':'\n');
			x/=2;
		}
	}
	return 0;
}