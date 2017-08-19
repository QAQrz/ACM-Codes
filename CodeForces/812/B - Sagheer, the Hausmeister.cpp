#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,l[22],r[22],ans=0x3f3f3f3f;
char s[22][111];
void dfs(int x,int f,int sum){
	if(x==n-1){
		if(f)
			ans=min(ans,sum?sum+m+1:r[x]);
		else
			ans=min(ans,sum+r[x]*2);
		return;
	}
	if(f){
		if(l[x]){
			dfs(x+1,0,sum?sum+m+2:r[x]+1);
			dfs(x+1,1,sum?sum+2*(m+1-l[x])+1:m+2-l[x]);
		}
		else{
			dfs(x+1,0,sum?sum+m+2:0);
			dfs(x+1,1,sum?sum+1:0);
		}
	}
	else{
		if(r[x]){
			dfs(x+1,0,sum?sum+r[x]*2+1:r[x]+1);
			dfs(x+1,1,sum?sum+m+2:m+2-l[x]);
		}
		else{
			dfs(x+1,0,sum?sum+1:0);
			dfs(x+1,1,sum?sum+m+2:0);
		}
	}
}
int main(){
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>s[i];
		for(j=0;j<m+2;j++)
			if(s[i][j]=='1'){
				if(!l[i])
					l[i]=j;
				r[i]=j;
			}
	}
	if(n>1){
		dfs(1,0,r[0]?r[0]+1:0);
		dfs(1,1,l[0]?m+2-l[0]:0);
	}
	else
		ans=r[0];
	cout<<ans<<endl;
	return 0;
}