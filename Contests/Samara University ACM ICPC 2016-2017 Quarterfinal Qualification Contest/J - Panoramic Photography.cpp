#include <bits/stdc++.h>
using namespace std;
long long n,i,a[222222],ans;
int main(){
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>a[i-1])
			ans+=a[i]-a[i-1];
	}
	cout<<ans<<endl;
	return 0;
}