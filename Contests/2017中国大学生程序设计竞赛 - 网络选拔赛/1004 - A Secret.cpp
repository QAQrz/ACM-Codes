#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define db(x) cout<<(x)<<endl
#define ms(x,y) memset(x,y,sizeof x)
#define mp(x,y) make_pair(x,y)
const LL mod=1e9+7,inf=0x3f3f3f3f,maxn=1123456;
const double eps=1e-8,PI=acos(-1.0);
LL t,nt[maxn],ans,l1,l2,num[maxn];
char s1[maxn],s2[maxn];
inline void makenext(){
	int j=-1,i=0;
	nt[0]=-1;
	while(i<l2){
		while(~j&&s2[j]!=s2[i])
			j=nt[j];
		nt[++i]=++j;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>s1>>s2;
		ms(num,0);
		l1=strlen(s1),l2=strlen(s2),ans=0;
		for(int i=0;i<l1/2;i++)
			swap(s1[i],s1[l1-i-1]);
		for(int i=0;i<l2/2;i++)
			swap(s2[i],s2[l2-i-1]);
		makenext();
		int i=0,j=0;
		while(i<l1){
			while(~j&&s1[i]!=s2[j])
				j=nt[j];
			i++,j++,num[j]++;
			if(j>=l2)
				j=nt[j];
		}
		for(int i=l2;i;i--){
			ans=(ans+num[i]*i)%mod;
			if(~nt[i])
				num[nt[i]]=(num[nt[i]]+num[i])%mod;
		}
		db(ans);
	}
	return 0;
}