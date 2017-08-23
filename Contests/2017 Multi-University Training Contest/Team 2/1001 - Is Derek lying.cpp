#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAX=1e5+10;
int t,n,x,y;
char s1[MAX],s2[MAX];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&n,&x,&y);
		scanf("%s %s",s1,s2);
		int cnt=0;
		for(int i=0;i<n;i++)
			if(s1[i]==s2[i])
				cnt++;
		if(x+y-n<=cnt&&abs(x-y)<=n-cnt)
			printf("Not lying\n");
		else
			printf("Lying\n");
	}
	return 0;
}