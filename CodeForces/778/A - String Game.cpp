#include <bits/stdc++.h>
using namespace std;
int a[222222],len,lens,l,r,i,ans,vis[222222],t,m;
char s[222222],str[222222];
int main(){
	cin>>s>>str;
	len=strlen(s),lens=strlen(str),l=0,r=len-lens;
	for(i=0;i<len;i++)
		cin>>a[i];
	while(l<=r){
		t=0,m=(l+r)/2;
		memset(vis,0,sizeof vis);
		for(i=m;i<len;i++)
			vis[a[i]-1]=1;
		for(i=0;i<len;i++)
			if(vis[i]&&s[i]==str[t]){
				t++;
				if(t>=lens)
					break;
			}
		if(t>=lens)
			ans=m,l=m+1;
		else
			r=m-1;
	}
	cout<<ans<<endl;
	return 0;
}