#include <bits/stdc++.h>
using namespace std;
int n,a[1024],x,t=1,i,ans;
int main(){
	cin>>n;
	for(i=1;i<=n;i++)
		a[i]=100;
	while(n--){
		cin>>x;
		for(i=1;i<t;i++)
			if(a[i]>=x){
				a[i]-=x,ans=i;
				break;
			}
		if(i>=t)
			ans=t,a[t++]-=x;
		cout<<x<<" "<<ans<<endl;
	}
	cout<<t-1<<endl;
	return 0;
}