#include <bits/stdc++.h>
using namespace std;
struct node{
	long long a,b;
}p[128];
long long n,i,a,b=1,g;
long long gcd(long long a,long long b){
	return b?gcd(b,a%b):a;
}
long long lcm(long long a,long long b){
	return a/gcd(a,b)*b;
}
int main(){
	scanf("%lld",&n);
	for(i=0;i<n;i++){
		scanf("%lld/%lld",&p[i].a,&p[i].b);
		b=lcm(b,p[i].b);
	}
	for(i=0;i<n;i++)
		a+=b/p[i].b*p[i].a;
	b*=n,g=gcd(a,b);
	a/=g,b/=g;
	printf("%lld",a);
	if(b>1)
		printf("/%lld",b);
	printf("\n");
	return 0;
}