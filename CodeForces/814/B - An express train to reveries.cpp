#include <bits/stdc++.h>
using namespace std;
int n,i,a[1123],b[1123],p,p1,vis[1123],x,x1;
int main(){
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++){
		cin>>b[i];
		if(a[i]!=b[i]){
			if(p)
				p1=i;
			else
				p=i;
		}
		else
			vis[a[i]]++;
	}
	if(p1){
		for(i=1;i<=n;i++)
			if(!vis[i])
				if(x)
					x1=i;
				else
					x=i;
		if((a[p]==x||b[p]==x)&&(a[p1]==x1||b[p1]==x1))
			a[p]=x,a[p1]=x1;
		else
			a[p]=x1,a[p1]=x;
	}
	else
		for(i=1;i<=n;i++)
			if(!vis[i]){
				a[p]=i;
				break;
			}
	for(i=1;i<=n;i++)
		printf("%d%c",a[i],i<n?' ':'\n');
	return 0;
}