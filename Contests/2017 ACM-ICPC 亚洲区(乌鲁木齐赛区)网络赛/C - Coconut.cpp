#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
#define pf(x) push_front(x)
#define pb(x) push_back(x)
typedef long long LL;
const double pi=acos(-1),eps=1e-9;
const LL inf=0x3f3f3f3f,maxn=1123;
LL t,n,c[maxn],d[maxn],b,ans,flag;
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		ans=0,flag=1;
		cin>>n>>b;
		for(LL i=1;i<=n;i++)
			cin>>c[i];
		for(LL i=1;i<n;i++){
			cin>>d[i];
			if(flag){
				ans+=c[i];
				if(ans<d[i]*b)
					flag=0;
				else
					ans-=d[i]*b;
			}
		}
		db(flag?"Yes":"No");
	}
	return 0;
}