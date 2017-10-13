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
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=112345,logmaxn=22,maxc=128;
struct sa{
	LL a[maxn],c[maxn],sa[maxn],rk[maxn],height[maxn],rmq[maxn][logmaxn],t1[maxn],t2[maxn],n,m,p,*x,*y;
	// maxn:character total length + number of strings
	// logmaxn:log2(maxn)
	// maxc:character set size
	inline void init(){
		n=p=0,m=maxc,x=t1,y=t2;
	}
	inline LL toid(char c){
		// transform character(from 1)
		return c-'a'+1;
	}
	inline void insert(char *s){
		while(*s)
			a[n++]=toid(*s++);
		a[n++]=0;
	}
	inline void build(){
		for(LL i=0;i<m;i++)
			c[i]=0;
		for(LL i=0;i<n;i++)
			c[x[i]=a[i]]++;
		for(LL i=1;i<m;i++)
			c[i]+=c[i-1];
		for(LL i=n-1;~i;i--)
			sa[--c[x[i]]]=i;
		for(LL k=1;k<=n&&p<n;k<<=1){
			m=p,p=0;
			for(LL i=n-k;i<n;i++)
				y[p++]=i;
			for(LL i=0;i<n;i++)
				if(sa[i]>=k)
					y[p++]=sa[i]-k;
			for(LL i=0;i<m;i++)
				c[i]=0;
			for(LL i=0;i<n;i++)
				c[x[y[i]]]++;
			for(LL i=1;i<m;i++)
				c[i]+=c[i-1];
			for(LL i=n-1;~i;i--)
				sa[--c[x[y[i]]]]=y[i];
			swap(x,y);
			p=0;
			for(LL i=0;i<n;i++)
				x[sa[i]]=i&&y[sa[i-1]]==y[sa[i]]&&(sa[i-1]+k<n?y[sa[i-1]+k]:n)==(sa[i]+k<n?y[sa[i]+k]:n)?p-1:p++;
		}
		for(LL i=0;i<n;i++)
			rk[sa[i]]=i;
		for(LL i=0,k=0;i<n;i++)
			if(!rk[i])
				height[0]=0;
			else{
				if(k)
					k--;
				LL j=sa[rk[i]-1];
				while(i+k<n&&j+k<n&&a[i+k]==a[j+k])
					k++;
				height[rk[i]]=k;
			}
	}
	inline void initrmq(){
		for(LL i=0;i<n;i++)
			rmq[i][0]=height[i];
		for(LL j=1;(1<<j)<=n;j++)
			for(LL i=0;i+(1<<j)-1<n;i++)
				rmq[i][j]=min(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
	}
	inline LL query(LL l,LL r){
		LL k=0;
		while((1<<(k+1))<=r-l+1)
			k++;
		return min(rmq[l][k],rmq[r-(1<<k)+1][k]);
	}
	inline LL ranklcp(LL l,LL r){
		if(l==r)
			return n-sa[l]-1;
		return query(l+1,r);
	}
	inline LL lcp(LL l,LL r){
		return ranklcp(min(rk[l],rk[r]),max(rk[l],rk[r]));
	}
}sa;
LL t,l,k,ans;
char s[maxn];
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>k>>s;
		ans=0,l=strlen(s);
		sa.init();
		sa.insert(s);
		sa.build();
		sa.initrmq();
		for(LL i=1;i+k-1<=l;i++){
			ans+=sa.ranklcp(i,i+k-1);
			if(i>1)
				ans-=sa.ranklcp(i-1,i+k-1);
			if(i+k<=l)
				ans-=sa.ranklcp(i,i+k);
			if(i>1&&i+k<=l)
				ans+=sa.ranklcp(i-1,i+k);
		}
		db(ans);
	}
	return 0;
}