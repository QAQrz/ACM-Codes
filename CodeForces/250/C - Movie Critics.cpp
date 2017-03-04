#include <bits/stdc++.h>
using namespace std;
int n,k,a[100086],x,i,ans,t,num[100086];
int main(){
	cin>>n>>k;
	for(i=0;i<n;i++){
		cin>>x;
		if(!i||x!=a[t-1])
			a[t++]=x;
	}
	for(i=0;i<t;i++){
		num[a[i]]++;
		if(i&&i<t-1&&a[i-1]==a[i+1])
			num[a[i]]++;
	}
	for(i=1;i<=k;i++)
		if(num[i]>num[ans])
			ans=i;
	cout<<ans<<endl;
	return 0;
}