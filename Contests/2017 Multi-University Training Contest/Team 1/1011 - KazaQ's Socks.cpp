#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,p,x,y,ans,t=1;
int main(){
	while(~scanf("%lld%lld",&n,&m)){
		if(m<=n)
			ans=m;
		else{
			m-=n,m=m%(2*(n-1));
			if(!m)
				ans=n;
			else if(m<=n-1)
				ans=m;
			else{
				m%=(n-1);
				if(!m)
					ans=n;
				else
					ans=m;
			}
		}
		printf("Case #%d: %lld\n",t++,ans);
	}
	return 0;
}