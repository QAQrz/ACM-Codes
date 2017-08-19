#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const LL mod=1e9+7,inf=0x3f3f3f3f,maxn=1123456;
LL n,sum,a,flag;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		sum+=a;
		if(a%2)
			flag=1;
	}
	db((sum%2||flag)?"First":"Second");
	return 0;
}