#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define db(x) cout<<(x)<<endl
#define ms(x,y) memset(x,y,sizeof x)
#define mp(x,y) make_pair(x,y)
const LL mod=1e9+7,inf=0x3f3f3f3f,maxn=1123456;
const double eps=1e-8,PI=acos(-1.0);
LL t,n,ans;
int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--) {
		cin>>n;
		ans=0;
		LL sum =0;
		for(LL i=1;; i++) {
			sum = i*i*2;
			if(sum>=n) {
				ans=i*4;
				break;
			} else {
				sum+=i-1;
				if(sum>=n) {
					ans=i*4+1;
					break;
				} else {
					sum+=i+1;
					if(sum>=n) {
						ans = i*4+2;
						break;
					} else {
						sum+=i;
						if(sum>=n) {
							ans = i*4+3;
							break;
						}
					}
				}
			}
		}
		db(ans);
	}
	return 0;
}