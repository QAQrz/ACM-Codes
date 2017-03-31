#include <bits/stdc++.h>
using namespace std;
int a,i,j,n,vis[10],x,num;
int main(){
	cin>>a>>n;
	for(i=a;;i++){
		x=i,num=0;
		memset(vis,0,sizeof vis);
		for(j=0;j<4;j++)
			vis[x%10]=1,x/=10;
		for(j=0;j<10;j++)
			if(vis[j])
				num++;
		if(num==n)
			break;
	}
	printf("%d %04d\n",i-a,i);
	return 0;
}