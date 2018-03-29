#include <bits/stdc++.h>
using namespace std;
long long n,a,b,c,d,x,p,q;
long long lcm(long long a,long long b){
	return a/__gcd(a,b)*b;
}
int main(){
	scanf("%lld %lld/%lld",&n,&a,&b);
	while(--n){
		scanf("%lld/%lld",&c,&d);
		x=lcm(b,d),p=x/b,q=x/d,b=d=x,a*=p,c*=q,a+=c;
		x=__gcd(a,b);
		a/=x,b/=x;
	}
	if(abs(a)>=b){
		printf("%lld",a/b);
		a=abs(a);
	}
	if(a%b){
		if(a>=b)
			printf(" ");
		printf("%lld/%lld\n",a%b,b);
	}
	return 0;
}