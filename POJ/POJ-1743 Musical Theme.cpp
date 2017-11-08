#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
#pragma comment(linker,"/stack:1024000000,1024000000")
#define db(x) cout<<(x)<<endl
#define pf(x) push_front(x)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const double pi=acos(-1),eps=1e-9;
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=21234,logmaxn=22,maxc=228;
int n,v[maxn],ans,l,r,mid;
struct sa{
	int a[maxn],c[maxn],sa[maxn],rk[maxn],height[maxn],rmq[maxn][logmaxn],t1[maxn],t2[maxn],n,m,p,*x,*y,mini,maxi;
	inline void init(){
		n=p=0,m=maxc,x=t1,y=t2;
	}
	inline void insert(int x){
		for(int i=1;i<x;i++)
			a[n++]=v[i]-v[i-1]+88;
		a[n++]=0;
	}
	inline void build(){
		for(int i=0;i<m;i++)
			c[i]=0;
		for(int i=0;i<n;i++)
			c[x[i]=a[i]]++;
		for(int i=1;i<m;i++)
			c[i]+=c[i-1];
		for(int i=n-1;~i;i--)
			sa[--c[x[i]]]=i;
		for(int k=1;k<=n&&p<n;k<<=1){
			m=p,p=0;
			for(int i=n-k;i<n;i++)
				y[p++]=i;
			for(int i=0;i<n;i++)
				if(sa[i]>=k)
					y[p++]=sa[i]-k;
			for(int i=0;i<m;i++)
				c[i]=0;
			for(int i=0;i<n;i++)
				c[x[y[i]]]++;
			for(int i=1;i<m;i++)
				c[i]+=c[i-1];
			for(int i=n-1;~i;i--)
				sa[--c[x[y[i]]]]=y[i];
			swap(x,y);
			p=0;
			for(int i=0;i<n;i++)
				x[sa[i]]=i&&y[sa[i-1]]==y[sa[i]]&&(sa[i-1]+k<n?y[sa[i-1]+k]:n)==(sa[i]+k<n?y[sa[i]+k]:n)?p-1:p++;
		}
		for(int i=0;i<n;i++)
			rk[sa[i]]=i;
		for(int i=0,k=0;i<n;i++)
			if(!rk[i])
				height[0]=0;
			else{
				if(k)
					k--;
				int j=sa[rk[i]-1];
				while(i+k<n&&j+k<n&&a[i+k]==a[j+k])
					k++;
				height[rk[i]]=k;
			}
	}
	inline bool check(int x){
		mini=inf,maxi=-inf;
		for(int i=1;i<n;i++)
			if(height[i]>=x){
				mini=min(mini,min(sa[i],sa[i-1])),maxi=max(maxi,max(sa[i],sa[i-1]));
				if(maxi-mini>x)
					return 1;
			}
			else
				mini=inf,maxi=-inf;
		return 0;
	}
}sa;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n&&n){
		for(int i=0;i<n;i++)
			cin>>v[i];
		sa.init();
		sa.insert(n);
		sa.build();
		ans=0,l=4,r=n>>1;
		while(l<=r){
			mid=(l+r)>>1;
			if(sa.check(mid))
				ans=l=mid+1;
			else
				r=mid-1;
		}
		db(ans);
	}
	return 0;
}