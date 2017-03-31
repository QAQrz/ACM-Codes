#include <bits/stdc++.h>
using namespace std;
long long a[111111],n,i,ans,x;
int main(){
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n-1;i++)
		a[i]=abs(a[i]-a[i+1]);
	for(i=0;i<n-1;i++){
		if(i%2)
			x-=a[i];
		else
			x+=a[i];
		x=max(x,0LL),ans=max(ans,x);
	}
	for(i=1,x=0;i<n-1;i++){
		if(i%2)
			x+=a[i];
		else
			x-=a[i];
		x=max(x,0LL),ans=max(ans,x);
	}
	cout<<ans<<endl;
	return 0;
}