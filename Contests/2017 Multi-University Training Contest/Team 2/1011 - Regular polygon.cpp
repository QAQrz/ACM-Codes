#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAX=1e5+10;
int x[MAX],y[MAX],n,mp[1000][1000],x3,y3,x4,y4;
int main(){
	while(~scanf("%d",&n)){
		memset(mp,0,sizeof mp);
		for(int i=0;i<n;i++){
			scanf("%d %d",&x[i],&y[i]);
			mp[x[i]+500][y[i]+500]++;
		}
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				x3=x[i]+y[i]-y[j],y3=y[i]-(x[i]-x[j]),x4=x[j]+y[i]-y[j],y4=y[j]-(x[i]-x[j]);
				if(mp[x3+500][y3+500]&&mp[x4+500][y4+500])
					ans++;
				x3=x[i]-(y[i]-y[j]),y3=y[i]+x[i]-x[j],x4=x[j]-(y[i]-y[j]),y4=y[j]+x[i]-x[j];
				if(mp[x3+500][y3+500]&&mp[x4+500][y4+500])
					ans++;
			}
		}
		printf("%d\n",ans/4);
	}
	return 0;
}