#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
typedef long long LL;
LL t,p,ans,k;
int main(){
	cin>>t;
	while(t--){
		cin>>p;
		ans=0;
		for(LL i=sqrt(p--);i;i--){
			if(i*i==p)
				ans++;
			else if(!(p%i))
				ans+=2;
		}
		db(ans);
	}
	return 0;
}