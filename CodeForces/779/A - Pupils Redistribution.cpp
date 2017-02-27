#include <bits/stdc++.h>
using namespace std;
int n,a[9],b[9],i,x,ans;
int main(){
	cin>>n;
	for(i=0;i<n;i++){
		cin>>x;
		a[x]++;
	}
	for(i=0;i<n;i++){
		cin>>x;
		b[x]++;
	}
	for(i=1;i<6;i++){
		if((a[i]+b[i])%2){
			ans=-2;
			break;
		}
		ans+=abs((a[i]+b[i])/2-a[i]);
	}
	cout<<ans/2<<endl;
	return 0;
}