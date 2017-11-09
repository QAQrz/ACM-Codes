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
typedef long long LL;
const double pi=acos(-1),eps=1e-9;
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=1123456;
int t,n,ans;
string s[8][22],str,b[112];
int main(){
	cin>>t;
	for(int cs=1;cs<=t;cs++){
		ans=inf;
		cin>>n>>str;
		for(int i=0;i<5;i++)
			for(int j=0;j<20;j++)
				cin>>s[i][j];
		for(int i=0;i<20;i++)
			cin>>b[i];
		for(int i=0; i<=n; ++i) {
			int num1 = n-i, num2 = i;
			map<string, bool> mp;
			int cnt = 0;
			bool ok = false;
			if(num1 == 0) ok = true;
			for(int j=0; j<20 && !ok; ++j) {
				for(int k=0; k<5 && !ok; ++k) {
					if(mp[s[k][j]]) continue;
					mp[s[k][j]] = true;
					cnt++;
					if(cnt == num1) ok = true;
				}
			}
			for(int j=0; j<20 && num2; ++j) {
				if(mp[b[j]]) continue;
				mp[b[j]] = true;
				cnt++;
				if(cnt == n) break;
			}
			if(!mp[str]) {
				ans = i;
				break;
			}
		}
		cout << "Case #" << cs << ": ";
		if(ans == inf) cout << "ADVANCED!" << endl;
		else cout << ans << endl;
	}
	return 0;
}