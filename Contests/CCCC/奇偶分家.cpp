#include <bits/stdc++.h>
using namespace std;
int a,b,n,i,x;
int main(){
	cin>>n;
	while(n--){
		cin>>x;
		if(x%2)
			a++;
		else
			b++;
	}
	cout<<a<<" "<<b<<endl;
	return 0;
}