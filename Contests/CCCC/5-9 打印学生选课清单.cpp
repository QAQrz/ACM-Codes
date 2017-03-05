#include <bits/stdc++.h>
using namespace std;
vector<int>v[180000];
int n,k,i,id,x,t,l,vis[180000];
char s[15];
int main(){
	scanf("%d %d",&n,&k);
	while(k--){
		scanf("%d %d",&id,&x);
		while(x--){
			scanf("%s",s);
			t=(s[0]-'A')*6760+(s[1]-'A')*260+(s[2]-'A')*10+(s[3]-'0');
			v[t].push_back(id);
		}
	}
	while(n--){
		scanf("%s",s);
		t=(s[0]-'A')*6760+(s[1]-'A')*260+(s[2]-'A')*10+(s[3]-'0');
		l=v[t].size();
		if(!vis[t]){
			sort(v[t].begin(),v[t].begin()+l);
			vis[t]=1;
		}
		printf("%s %d",s,l);
		for(i=0;i<l;i++)
			printf(" %d",v[t][i]);
		printf("\n");
	}
	return 0;
}