#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker,"/stack:1024000000,1024000000")
#define db(x) cout<<(x)<<endl
#define pf(x) push_front(x)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ms(x,y) memset(x,y,sizeof x)
typedef long long LL;
const double pi=acos(-1),eps=1e-9;
const LL inf=0x3f3f3f3f,mod=1e9+7,maxn=1024;
int n,p,flag=1;
double a[maxn];
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(p=3;p<=n;p++)
		if(abs((a[p]-a[p-1])-(a[p]-a[1])/(p-1))>eps)
			break;
	if(p>n){
		db("No");
		return 0;
	}
	for(int i=3;i<=n;i++)
		if(i!=p)
			if(abs((a[2]-a[1])-(a[i]-a[1])/(i-1))>eps&&abs((a[2]-a[1])-(a[i]-a[p])/(i-p))>eps){
				flag=0;
				break;
			}
	if(!flag){
		flag=1;
		for(int i=3;i<=n;i++)
			if(i!=p)
				if(abs((a[p]-a[1])/(p-1)-(a[i]-a[2])/(i-2))>eps&&abs((a[p]-a[1])/(p-1)-(a[i]-a[1])/(i-1))>eps){
					flag=0;
					break;
				}
	}
	if(!flag){
		flag=1;
		for(int i=3;i<=n;i++)
			if(i!=p)
				if(abs((a[p]-a[2])/(p-2)-(a[i]-a[2])/(i-2))>eps&&abs((a[p]-a[2])/(p-2)-(a[i]-a[1])/(i-1))>eps){
					flag=0;
					break;
				}
	}
	db(flag?"Yes":"No");
	return 0;
}