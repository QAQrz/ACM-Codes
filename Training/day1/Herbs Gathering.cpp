#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const LL mod=1e9+7,inf=0x3f3f3f3f,maxn=128;
LL n,m,a,b,maxi;
int main(){
	ios::sync_with_stdio(false);
	while(cin>>n>>m){
		map<LL,LL>mmp;
		map<LL,LL>::iterator it;
		mmp[0]=0;
		for(int i=0;i<n;i++){
			cin>>a>>b;
			for(it=mmp.end(),it--;;it--){
				if(it->first+a<=m)
					mmp[it->first+a]=max(mmp[it->first]+b,mmp[it->first+a]);
				if(it==mmp.begin())
					break;
			}
			for(it=mmp.begin(),maxi=-1;it!=mmp.end();)
				if(it->second>maxi)
					maxi=it->second,it++;
				else
					mmp.erase(it++);
		}
		it=mmp.end();
		db((--it)->second);
	}
	return 0;
}