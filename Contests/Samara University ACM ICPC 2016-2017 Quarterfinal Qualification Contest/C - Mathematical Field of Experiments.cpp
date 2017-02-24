#include <bits/stdc++.h>
using namespace std;
long long ans[1111111],i,n;
int main(){
	cin>>n;
	memset(ans,-1,sizeof ans);
	for(i=0;i<n;i++)
		ans[(i*i)%n]=i;
	for(i=0;i<n;i++)
		cout<<ans[i]<<(i<n-1?' ':'\n');
	return 0;
}