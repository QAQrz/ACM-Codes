#include <bits/stdc++.h>
using namespace std;
int n,i,j,q,m,num[2123][33],ans[2123][33],k,l,r,mid,p,x;
char s[2123],op[5];
int main(){
	scanf("%d %s %d",&n,s,&q);
	for(i=0;i<n;i++)
		num[i+1][s[i]-'a']++;
	for(i=1;i<=n+1;i++)
		for(j=0;j<26;j++)
			num[i][j]+=num[i-1][j];
	for(i=1;i<=n;i++)
		for(j=0;j<26;j++){
			for(x=-1,k=1;k<=n-i+1;k++){
				l=k+i-1,r=n,p=-1;
				while(l<=r){
					mid=(l+r)/2;
					if(mid-k+1>i+num[mid][j]-num[k-1][j])
						r=mid-1;
					else
						l=mid+1,p=mid-k+1;
				}
				x=max(p,x);
			}
			ans[i][j]=x;
		}
	while(q--){
		scanf("%d %s",&m,op);
		printf("%d\n",ans[m][op[0]-'a']);
	}
	return 0;
}