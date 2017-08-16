#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
typedef long long LL;
int n,k,i,sum,a;
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>a;
		sum+=a;
		if(sum>7)
			sum-=8,k-=8;
		else
			k-=sum,sum=0;
		if(k<1){
			k=0;
			break;
		}
	}
	db(k?-1:i);
	return 0;
}