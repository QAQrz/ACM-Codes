#include <bits/stdc++.h>
using namespace std;
#define db(x) cout<<(x)<<endl
typedef long long LL;
int n,k,suma,sumb,sumc,a,b;
int main(){
	ios::sync_with_stdio(false);
	cin>>k>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		suma+=a/4,sumb+=a%4/2,sumc+=a%2;
	}
	a=k,b=k*2;
	if(a>=suma){
		a-=suma,suma=0;
		db((sumb<=a+b||(sumb-a-b)*2+sumc<=a)&&sumb+sumc<=a*2+b?"YES":"NO");
	}
	else{
		suma-=a,a=0;
		db(suma*2+sumb+sumc>b?"NO":"YES");
	}
	return 0;
}