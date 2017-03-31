#include <bits/stdc++.h>
using namespace std;
int n,k,ans,a;
int main(){
	cin>>n>>k;
	while(n--){
		cin>>a;
		ans+=a/k+(a%k?1:0);
	}
	cout<<(ans/2+ans%2)<<endl;
	return 0;
}