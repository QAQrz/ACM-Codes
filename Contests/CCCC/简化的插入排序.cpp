#include <bits/stdc++.h>
using namespace std;
int n,a[15],i;
int main(){
	cin>>n;
	for(i=0;i<=n;i++)
		cin>>a[i];
	sort(a,a+n+1);
	for(i=0;i<=n;i++)
		printf("%d ",a[i]);
	cout<<endl;
	return 0;
}