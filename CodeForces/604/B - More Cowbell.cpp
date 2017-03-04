#include <bits/stdc++.h>
using namespace std;
int n,k,i,ans,a[100086];
int main(){
	cin>>n>>k;
	for(i=0;i<n;i++)
		cin>>a[i];
	ans=a[n-1];
	if(n>k)
		for(i=0;i<n-k;i++)
			ans=max(ans,a[i]+a[n*2-k*2-i-1]);
	cout<<ans<<endl;
	return 0;
}