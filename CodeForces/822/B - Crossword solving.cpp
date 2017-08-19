#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const LL mod=1e9+7,inf=0x3f3f3f3f,maxn=1024;
int ans,a[maxn],top,p[maxn],l,l1;
char s[maxn],t[maxn];
int main(){
	ios::sync_with_stdio(0);
	cin>>l>>l1>>s>>t;
	ans=inf;
	for(int i=0;i<l1-l+1;i++){
		for(int j=top=0;j<l;j++)
			if(s[j]!=t[i+j])
				a[top++]=j+1;
		if(top<ans){
			ans=top;
			memcpy(p,a,sizeof a);
		}
	}
	db(ans);
	for(int i=0;i<ans;i++)
		printf("%d%c",p[i],i<ans-1?' ':'\n');
	return 0;
}