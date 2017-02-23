#include <bits/stdc++.h>
using namespace std;
int n,i,s[10086][2],m[10086],a,b,top;
int main(){
	while(cin>>n){
		top=0;
		memset(s,0,sizeof s);
		memset(m,0,sizeof m);
		for(i=1;i<n;i++){
			scanf("%d %d",&a,&b);
			if(m[a]<2&&m[b]<2)
				s[a][m[a]++]=++top,s[b][m[b]++]=top;
			else if(m[a]>1)
				s[b][m[b]++]=s[a][1];
			else
				s[a][m[a]++]=s[b][1];
		}
		for(i=1;i<=n;i++)
			cout<<s[i][0]<<" "<<s[i][1]<<endl;
	}
	return 0;
}