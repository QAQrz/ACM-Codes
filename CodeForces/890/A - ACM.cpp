#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker,"/stack:1024000000,1024000000")
#define db(x) cout<<(x)<<endl
#define pc(x) putchar(x)
#define ps(x) puts(x)
#define pf(x) push_front(x)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const double pi=acos(-1),eps=1e-9;
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=1123456;
int a[11],s,flag;
void dfs(int x,int y,int z){
	if(y*2==s&&z==3)
		flag=1;
	if(flag||x>5)
		return;
	dfs(x+1,y+a[x],z+1);
	dfs(x+1,y,z);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i=0;i<6;i++){
		cin>>a[i];
		s+=a[i];
	}
	dfs(0,0,0);
	db(flag?"Yes":"No");
	return 0;
}