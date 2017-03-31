#include <bits/stdc++.h>
using namespace std;
int a[111111],sum1,sum2,n,i,ans;
int main(){
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(i=0;i<n;i++){
		if(i<n/2)
			sum1+=a[i];
		sum2+=a[i];
	}
	ans=n/2;
	printf("Outgoing #: %d\nIntroverted #: %d\nDiff = %d\n",n-ans,ans,sum2-sum1*2);
	return 0;
}