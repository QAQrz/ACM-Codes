#include <bits/stdc++.h>
using namespace std;
int n,a[10],i;
int main(){
	cin>>n;
	for(i=0;i<n;i++)
		a[i]=i+1;
	do{
		for(i=0;i<n;i++){
			cout<<a[i];
			if(i>n-2)
				cout<<endl;
		}
	}while(next_permutation(a,a+n));
	return 0;
}