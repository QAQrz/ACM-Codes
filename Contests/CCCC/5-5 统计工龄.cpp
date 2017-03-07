#include <bits/stdc++.h>
using namespace std;
int a[55],n,x,i;
int main(){
	cin>>n;
	while(n--){
		cin>>x;
		a[x]++;
	}
	for(i=0;i<51;i++)
		if(a[i])
			cout<<i<<":"<<a[i]<<endl;
	return 0;
}