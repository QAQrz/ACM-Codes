#include <bits/stdc++.h>
using namespace std;
int num[100086],vis[100086],n,i,k,a,ans[100086],t;
int main(){
	cin>>n;
	while(n--){
		cin>>k;
		if(k>1)
			while(k--){
				cin>>a;
				num[a]++;
			}
		else
			cin>>a;
	}
	cin>>k;
	while(k--){
		cin>>a;
		if(!num[a]&&!vis[a])
			ans[t++]=a,vis[a]=1;
	}
	if(t)
		for(i=0;i<t;i++)
			printf("%05d%c",ans[i],i<t-1?' ':'\n');
	else
		cout<<"No one is handsome"<<endl;
	return 0;
}