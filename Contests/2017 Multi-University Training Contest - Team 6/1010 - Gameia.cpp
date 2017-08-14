#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
typedef long long LL;
int t,n,k,p[512],a[512],flag;
int main(){
	scanf("%d",&t);
	while(t--){
		flag=1;
		scanf("%d %D",&n,&k);
		for(int i=2;i<=n;i++)
			scanf("%d",&p[i]);
		for(int i=1;i<=n;i++)
			a[i]=1;
		for(int i=n;i;i--)
			flag&=a[i]<3,a[p[i]]+=a[i]&1;
		printf("%s\n",!(n%2)&&k>=n/2-1&&flag?"Bob":"Alice");
	}
	return 0;
}