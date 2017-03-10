#include <bits/stdc++.h>
using namespace std;
int n,s,a[3],b,c;
int main(){
	cin>>n;
	if(n==495){
		cout<<"1: 954 - 459 = 495"<<endl;
		return 0;
	}
	while(n!=495&&n){
		a[0]=n/100,a[1]=n/10%10,a[2]=n%10;
		sort(a,a+3);
		b=a[0]*100+a[1]*10+a[2],c=a[2]*100+a[1]*10+a[0],n=c-b;
		printf("%d: %d - %d = %d\n",++s,c,b,n);
	}
	return 0;
}