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
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=112345;
int n,k,m,a[maxn],b[maxn],ans,num,flag;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[a[i]%m]++;
		if(b[a[i]%m]>=k)
			ans=a[i]%m,flag=1;
	}
	if(flag){
		db("Yes");
		sort(a,a+n);
		for(int i=0;i<n&&num<k;i++)
			if(a[i]%m==ans){
				if(!num)
					printf("%d",a[i]);
				else
					printf(" %d",a[i]);
				num++;
			}
		ps("");
	}
	else
		db("No");
	return 0;
}