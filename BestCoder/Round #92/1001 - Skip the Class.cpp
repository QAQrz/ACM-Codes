#include <bits/stdc++.h>
using namespace std;
struct node{
	int v;
	char s[15];
}p[128];
int t,n,i,j,top,ans;
char str[128][15],num[128];
int cmp(node a,node b){
	return a.v>b.v;
}
int main(){
	cin>>t;
	while(t--){
		ans=top=0;
		memset(num,0,sizeof num);
		cin>>n;
		for(i=0;i<n;i++){
			cin>>p[i].s>>p[i].v;
			for(j=0;j<top;j++)
				if(!strcmp(p[i].s,str[j]))
					break;
			if(j>=top)
				strcpy(str[top++],p[i].s);
		}
		sort(p,p+n,cmp);
		for(i=0;i<n;i++)
			for(j=0;j<top;j++)
				if(!strcmp(p[i].s,str[j])){
					if(num[j]<2)
						ans+=p[i].v,num[j]++;
					break;
				}
		cout<<ans<<endl;
	}
	return 0;
}