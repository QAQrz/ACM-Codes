#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL i,x,y,a,b,c,ans,p[1024],mod=1e9+7,n[1024],t;
LL exgcd(LL a,LL b,LL &x,LL &y){
	if(!b){
		x=1,y=0;
		return a;
	}
	LL r=exgcd(b,a%b,x,y),temp=x;
	x=y,y=temp-a/b*y;
	return r;
}
LL cal(LL a,LL m){
	LL ans,x,y,gcd=exgcd(a,m,x,y);
	if(1%gcd)
		return -1;
	x*=1/gcd,m=abs(m),ans=x%m;
	if(ans<=0)
		ans+=m;
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	p[0]=1,n[0]=cal(p[0],mod);
	for(i=1;i<1024;i++)
		p[i]=(p[i-1]*i)%mod,n[i]=cal(p[i],mod);
	cin>>t;
	while(t--){
		cin>>x>>y;
		if(x<y)
			swap(x,y);
		cout<<(p[x]*n[x-y]%mod*n[y]%mod)<<endl;
	}
	return 0;
}