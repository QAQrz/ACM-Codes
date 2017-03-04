#include <bits/stdc++.h>
using namespace std;
int n,a[100086],ans,i,h;
int main(){
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
		if(!i)
			ans+=a[i]+1;
		else if(a[i]<a[i-1])
			ans+=a[i-1]-a[i]+2;
		else
			ans+=a[i]-a[i-1]+2;
	}
	cout<<ans<<endl;
	return 0;
}