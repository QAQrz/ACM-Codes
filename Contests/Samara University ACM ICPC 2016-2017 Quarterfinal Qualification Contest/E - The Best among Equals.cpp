#include <bits/stdc++.h>
using namespace std;
long long n,i,l[222222],r[222222],ans,m;
int main(){
	cin>>n;
	for(i=0;i<n;i++){
		cin>>l[i]>>r[i];
		m=max(m,l[i]);
	}
	for(i=0;i<n;i++)
		if(r[i]>=m)
			ans++;
	cout<<ans<<endl;
	return 0;
}