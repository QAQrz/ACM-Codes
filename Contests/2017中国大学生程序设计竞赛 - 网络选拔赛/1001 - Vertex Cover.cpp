#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const LL mod=1e9+7,inf=0x3f3f3f3f,maxn=15;
int main(){
	printf("60 189\n");
	for(int i=1,s=maxn+1;i<=maxn;i++){
		for(int j=1,k=1;j<=maxn/i;j++,s++)
			for(int x=0;x<i;x++)
				printf("%d %d\n",k++,s);
	}
	db(maxn);
	for(int i=1;i<=maxn;i++)
		db(i);
	return 0;
}