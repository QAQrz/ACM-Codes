#include <cstdio>
#include <cstring>
using namespace std;
long long t,n,m,k,da[111111],db[111111],i,a[111111],b[111111],ans;
int main(){
	scanf("%lld",&t);
	while(t--){
		ans=0;
		scanf("%lld %lld %lld",&n,&m,&k);
		for(i=0;i<=n||i<=m;i++)
			da[i]=db[i]=0;
		for(i=0;i<k;i++){
			scanf("%lld %lld",&a[i],&b[i]);
			da[a[i]]++,db[b[i]]++;
		}
		for(i=0;i<k;i++)
			ans+=(da[a[i]]-1)*(db[b[i]]-1)*2;
		printf("%lld\n",ans);
	}
	return 0;
}