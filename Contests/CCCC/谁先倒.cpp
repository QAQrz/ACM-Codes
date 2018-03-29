#include <bits/stdc++.h>
using namespace std;
int n1,n2,n,a,b,c,d,numa,numb,ans;
int main(){
	cin>>n1>>n2>>n;
	while(n--){
		cin>>a>>b>>c>>d;
		if(!ans){
			if(b==a+c&&d!=a+c)
				numa++;
			if(b!=a+c&&d==a+c)
				numb++;
			if(numa>n1)
				ans=1;
			if(numb>n2)
				ans=2;
		}
	}
	if(ans<2)
		cout<<"A"<<endl<<numb<<endl;
	else
		cout<<"B"<<endl<<numa<<endl;
	return 0;
}