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
typedef unsigned long long ULL;
const double pi=acos(-1),eps=1e-9;
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=4123,maxc=26;
LL l,l1,a[maxn][maxc],b[maxn][maxc],ans;
char s[maxn],s1[maxn];
unordered_set<ULL>mmp;
inline bool check(int x){
	for(int i=0;i+x<=l1;i++){
		ULL r=2333;
		for(int j=0;j<maxc;j++)
			r+=(r<<4)+b[i+x][j]-b[i][j];
		if(mmp.count(r))
			return 1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>s>>s1;
	l=strlen(s),l1=strlen(s1);
	for(int i=0;i<l;i++){
		a[i+1][s[i]-'a']++;
		if(i)
			for(int j=0;j<maxc;j++)
				a[i+1][j]+=a[i][j];
	}
	for(int i=0;i<l1;i++){
		b[i+1][s1[i]-'a']++;
		if(i)
			for(int j=0;j<maxc;j++)
				b[i+1][j]+=b[i][j];
	}
	for(int i=0;i<l;i++)
		for(int j=i+1;j<=l;j++){
			ULL r=2333;
			for(int k=0;k<maxc;k++)
				r+=(r<<4)+a[j][k]-a[i][k];
			mmp.insert(r);
		}
	for(int i=min(l,l1);i;i--)
		if(check(i)){
			ans=i;
			break;
		}
	db(ans);
	return 0;
}