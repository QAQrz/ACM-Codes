#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,ans,a[1024][1024];
char s[1024][1024];
inline bool cmp(int a,int b){
	return a>b;
}
int main(){
	while(~scanf("%d %d",&n,&m)){
		ans=0;
		memset(a,0,sizeof a);
		for(i=0;i<n;i++)
			scanf("%s",s[i]);
		for(i=n-1;~i;i--)
			for(j=0;j<m;j++)
				if(s[i][j]-'0')
					a[i][j]=a[i+1][j]+1;
		for(i=0;i<n;i++){
			sort(a[i],a[i]+m,cmp);
			for(j=0;j<m;j++)
				ans=max(ans,a[i][j]*(j+1));
		}
		printf("%d\n",ans);
	}
	return 0;
}