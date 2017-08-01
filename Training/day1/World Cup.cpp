#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL t,n,m,a,b,c,k,a1,a2;
int main(){
	cin>>t;
	for(k=1;k<=t;k++){
		cin>>n>>m>>a>>b>>c;
		if(a<c)
			swap(a,c);
		if(b>a)
			a1=b*(n-1),a2=c*(m-1)+(n-m)/2*(a+c)+((n-m)%2)*a;
		else if(b<c)
			a1=a*(n-m-1)+m/2*(a+c)+(m%2)*c,a2=(n-1)*b;
		else if(b*2<a+c)
			a1=(n-m-1)*a+m/2*(a+c)+(m%2)*b,a2=(m-1)*c+(n-m)*b;
		else
			a1=(n-m-1)*a+m*b,a2=(m-1)*c+(n-m)/2*(a+c)+((n-m)%2)*b;
		printf("Case #%lld: %lld %lld\n",k,a1,a2);
	}
	return 0;
}