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
int n,k,num,a[33];
char s[1024];
int main(){
	ios::sync_with_stdio(0);
	cin>>s>>k;
	n=strlen(s);
	for(int i=0;i<n;i++){
		if(!a[s[i]-'a'])
			num++;
		a[s[i]-'a']++;
	}
	if(num>=k)
		db(0);
	else if(n>=k)
		db(k-num);
	else
		db("impossible");
	return 0;
}