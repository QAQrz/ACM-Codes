#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker,"/stack:1024000000,1024000000")
#define db(x) cout<<(x)<<endl
#define pc(x) putchar(x)
#define ps(x) puts(x)
#define pf(x) push_front(x)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef unsigned long long uLL;
const double pi=acos(-1),eps=1e-9;
const uLL inf=0x3f3f3f3f,mod=1e9+7,maxn=1123456;
uLL n,k,cnt,num,leave,ans;
int main(){
	cin>>n>>k;
	ans = inf;
	for(uLL i = 1; i<k; ++i){
		num = i, cnt = 1;
		while(num*3<=n){
			num*=2;
			cnt++;
		}
		leave = n-num;
		while(leave>k-i){
			leave = (leave+1)/2;
			cnt++;
		}
		ans = min(ans, cnt);
	}
	db(ans);
	return 0;
}