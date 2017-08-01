#include <bits/stdc++.h>
using namespace std;
int n,a,b,k,p[212345],t,ans[212345];
char s[212345];
int main(){
	cin>>n>>a>>b>>k>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			p[i]=i?p[i-1]+1:1;
			if(p[i]==b)
				ans[t++]=i+1,p[i]=0;
		}
	}
	t=max(t-a+1,1);
	cout<<t<<endl;
	for(int i=0;i<t;i++)
		printf("%d%c",ans[i],i<t-1?' ':'\n');
	return 0;
}