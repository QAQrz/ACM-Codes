#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
struct node{
	LL l,r;
}p[112345];
LL n,m,ans,t,l,r,sum;
inline bool cmp(node a,node b){
	if(a.l==b.l)
		return a.r>b.r;
	return a.l<b.l;
}
int main(){
	ios::sync_with_stdio(false);
	while(cin>>n>>m){
		vector<node>vec;
		sum=l=r=t=ans=0;
		for(int i=0;i<n;i++)
			cin>>p[i].l>>p[i].r;
		sort(p,p+n,cmp);
		for(int i=0;i<n;i++)
			if(!i||p[i].l>vec[t-1].r+1){
				t++;
				vec.pb(p[i]);
			}
			else if(p[i].l<=vec[t-1].r+1)
				vec[t-1].r=max(vec[t-1].r,p[i].r);
		while(r<t-1){
			while(r<t-1&&sum+vec[r+1].l-vec[r].r-1<=m)
				sum+=vec[r+1].l-vec[r].r-1,r++;
			ans=max(ans,vec[r].r-vec[l].l+1+m-sum),sum-=vec[l+1].l-vec[l].r-1,l++;
		}
		ans=max(ans,vec[r].r-vec[l].l+1+m-sum);
		db(ans);
	}
	return 0;
}