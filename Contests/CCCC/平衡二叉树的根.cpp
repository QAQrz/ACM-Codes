#include <bits/stdc++.h>
using namespace std;
int n,a[22],i;
int main(){
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(n>10){
		if(!(n%2))
			cout<<a[n/2+2]<<endl;
		else
			cout<<a[n/2]<<endl;
	}
	else
		cout<<a[(n+1)/2]<<endl;
	return 0;
}