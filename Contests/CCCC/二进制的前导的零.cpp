#include <bits/stdc++.h>
using namespace std;
long long a,ans;
int main(){
	cin>>a;
	if(a<0){
		cout<<0<<endl;
		return 0;
	}
	while(a)
		a>>=1,ans++;
	cout<<32-ans<<endl;
	return 0;
}