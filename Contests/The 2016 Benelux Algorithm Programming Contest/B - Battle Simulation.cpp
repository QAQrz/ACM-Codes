#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker,"/stack:1024000000,1024000000")
#define db(x) cout<<(x)<<endl
#define pf(x) push_front(x)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const double pi=acos(-1),eps=1e-9;
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=1123456;
LL l;
char s[maxn];
int main(){
	ios::sync_with_stdio(0);
	cin>>s;
	l=strlen(s);
	for(int i=0;i<l;i++)
		if(i+2<l&&s[i]!=s[i+1]&&s[i]!=s[i+2]&&s[i+1]!=s[i+2]){
			cout<<'C';
			i+=2;
		}
		else if(s[i]=='R')
			cout<<'S';
		else if(s[i]=='B')
			cout<<'K';
		else
			cout<<'H';
	cout<<endl;
	return 0;
}