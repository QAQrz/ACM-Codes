#include <bits/stdc++.h>
using namespace std;
int ans,a,i,j,n;
int main(){
	cin>>n;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			cin>>a;
			if(i+j!=n-1&&i!=n-1&&j!=n-1)
				ans+=a;
		}
	cout<<ans<<endl;
	return 0;
}