#include <bits/stdc++.h>
using namespace std;
int n,k,x,num[1024],i,ansnum,ans;
int main(){
	cin>>n;
	while(n--){
		cin>>k;
		while(k--){
			cin>>x;
			num[x]++;
		}
	}
	for(i=1000;i;i--)
		if(ansnum<num[i])
			ansnum=num[i],ans=i;
	printf("%d %d\n",ans,ansnum);
	return 0;
}