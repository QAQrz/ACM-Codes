#include <bits/stdc++.h>
using namespace std;
int n,m,a[128],b,i,ans;
int main(){
	cin>>n>>m;
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	ans=max(a[0]*2,a[n-1]);
	while(m--){
		cin>>b;
		if(b<=ans)
			ans=-1;
	}
	cout<<ans<<endl;
	return 0;
}