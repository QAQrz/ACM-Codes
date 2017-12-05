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
int a[33][33],ans,maxi,vis[33],tmp;
char s[maxn];
inline bool check(char c){
	return c!='a'&&c!='e'&&c!='i'&&c!='o'&&c!='u'&&c!='w'&&c!='y';
}
inline bool cal(int x){
	for(int i=0;i<26;i++)
		if(!vis[i]&&(x>>i)%2)
			return 1;
	return 0;
}
inline int solve(int x){
	int sum=0;
	for(int i=0;i<26;i++){
		if(!vis[i])
			continue;
		for(int j=0;j<26;j++){
			if(i==j||!vis[j]||(x>>i)%2==(x>>j)%2)
				continue;
			sum+=a[i][j];
		}
	}
	return sum;
}
int main(){
	freopen("consonant.in","r",stdin);
	freopen("consonant.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>s;
	for(int i=0;s[i];i++)
		if(check(s[i])&&s[i+1]&&check(s[i+1]))
			a[s[i]-'a'][s[i+1]-'a']++,vis[s[i]-'a']=vis[s[i+1]-'a']=1;
	for(int i=1<<26-1;~i;i--){
		if(cal(i))
			continue;
		tmp=solve(i);
		if(maxi<tmp)
			maxi=tmp,ans=i;
	}
	for(int i=0;i<26;i++)
		vis[i]=(ans>>i)%2;
	for(int i=0;s[i];i++)
		pc(vis[s[i]-'a']?s[i]-'a'+'A':s[i]);
	ps("");
	return 0;
}