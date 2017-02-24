#include <bits/stdc++.h>
using namespace std;
int n,ans,a;
int main(){
	cin>>n;
	while(n--){
		cin>>a;
		ans=max(ans,a);
	}
	cout<<ans<<endl;
	return 0;
}