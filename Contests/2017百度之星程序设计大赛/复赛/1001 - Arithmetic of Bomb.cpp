#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const LL mod=1e9+7,inf=0x3f3f3f3f,maxn=1123456;
LL t,ans,l,j,k,p,n;
char s[1024];
int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>s;
		l=strlen(s),ans=0;
		for(int i=0;i<l;i++){
			if(isdigit(s[i]))
				ans=(ans*10+s[i]-'0')%mod;
			else{
				for(j=i+1,p=1,k=0;s[j]!=')';j++)
					k=(k*10+s[j]-'0')%mod,p=p*10%mod;
				for(j+=3,n=0;s[j]!=')';j++)
					n=(n*10+s[j]-'0')%mod;
				i=j;
				while(n--)
					ans=(ans*p+k)%mod;
			}
		}
		db(ans);
	}
	return 0;
}