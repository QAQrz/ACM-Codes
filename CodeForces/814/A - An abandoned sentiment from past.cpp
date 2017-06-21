#include <bits/stdc++.h>
using namespace std;
int n,k,a[222],b[222],i;
int main(){
	cin>>n>>k;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<k;i++)
		cin>>b[i];
	sort(b,b+k);
	for(i=0;i<n;i++){
		if(!a[i])
			a[i]=b[--k];
		if(i&&a[i]<a[i-1])
			break;
	}
	cout<<(i<n?"Yes":"No")<<endl;
	return 0;
}