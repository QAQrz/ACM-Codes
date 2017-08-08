#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
typedef long long LL;
int n,a[212345],ans,pre[2123456];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		pre[a[i]+1]=a[i];
	}
	for(int i=1;i<2123456;i++)
		if(!pre[i])
			pre[i]=pre[i-1];
	sort(a,a+n);
	n=unique(a,a+n)-a;
	for(int i=0;i<n;i++)
		for(int j=2;j*a[i]<2123456;j++)
			ans=max(ans,pre[j*a[i]]%a[i]);
	db(ans);
	return 0;
}