#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const LL mod=1e9+7,inf=0x3f3f3f3f,maxn=112345;
struct node{
	int a,b;
}a[maxn],b[maxn];
int t,n,m,ans,f,p,s;
inline bool cmp(node a,node b){
	return a.a>b.a;
}
inline bool cmpb(node a,node b){
	return a.b>b.b;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	for(int k=1;k<=t;k++){
		vector<int>v;
		cin>>n>>m;
		s=f=0,ans=n;
		for(int i=0;i<n;i++)
			cin>>a[i].a>>a[i].b;
		for(int i=0;i<m;i++)
			cin>>b[i].a>>b[i].b;
		if(n<m)
			ans=-1;
		else{
			sort(a,a+n,cmp);
			sort(b,b+m,cmpb);
			for(int i=0;i<m;i++){
				while(f<n&&a[f].a>=b[i].b){
					v.insert(upper_bound(v.begin(),v.end(),a[f].b),a[f].b);
					s++,f++;
				}
				p=upper_bound(v.begin(),v.end(),b[i].a)-v.begin();
				if(p<s){
					v.erase(v.begin()+p);
					s--;
				}
				else if(s){
					v.erase(v.begin());
					s--,ans--;
				}
				else{
					ans=-1;
					break;
				}
			}
		}
		printf("Case #%d: %d\n",k,ans);
	}
	return 0;
}