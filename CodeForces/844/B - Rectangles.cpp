#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
#define pf(x) push_front(x)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const double pi=acos(-1),eps=1e-9;
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=1123456;
LL n,m,r[55],c[55],s[55][55],ans,r1[55],c1[55];
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			cin>>s[i][j];
			if(s[i][j])
				r[i]++,c[j]++;
			else
				r1[i]++,c1[j]++;
		}
	for(int i=0;i<n;i++)
		ans+=(1LL<<r[i])+(1LL<<r1[i])-2;
	for(int i=0;i<m;i++)
		ans+=(1LL<<c[i])+(1LL<<c1[i])-2;
	db(ans-n*m);
	return 0;
}