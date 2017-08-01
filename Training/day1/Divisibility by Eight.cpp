#include <bits/stdc++.h>
using namespace std;
int l,flag;
char s[128],ans[128];
void dfs(int p,int t,int sum,int q){
	if(sum&&!(sum%8))
		flag=1,ans[p]=0;
	if(flag||t>=l)
		return;
	ans[p]=s[t];
	if(!((q>>(((sum%8)*10+s[t]-'0')%8))&1))
		dfs(p+1,t+1,(sum%8)*10+s[t]-'0',(1<<(((sum%8)*10+s[t]-'0')%8))|q);
	dfs(p,t+1,sum,q);
}
int main(){
	cin>>s;
	l=strlen(s);
	for(int i=0;i<l;i++)
		if(s[i]=='0'||s[i]=='8'){
			flag=1,ans[0]=s[i];
			break;
		}
		else if((s[i]-'0'+1)%2)
			flag=2;
	if(flag==2){
		flag=0;
		dfs(0,0,0,0);
	}
	if(flag)
		cout<<"YES"<<endl<<ans<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}