#include <bits/stdc++.h>
using namespace std;
struct node{
	int ans;
	char s[22];
};
vector<node>vec[111111];
int n,k,x,num,i;
char s[22];
int main(){
	scanf("%d %d",&n,&k);
	while(n--){
		scanf("%s %d",s,&x);
		if(k>x)
			x=k;
		for(i=0,num=1;i<18;i++)
			if(s[i]=='x')
				num=(num*10+10)%100007;
			else
				num=(num*10+(s[i]-'0'))%100007;
		for(i=0;i<vec[num].size();i++)
			if(!strcmp(vec[num][i].s,s)){
				vec[num][i].ans+=x;
				break;
			}
		if(i>=vec[num].size()){
			node a;
			a.ans=x;
			strcpy(a.s,s);
			vec[num].push_back(a);
		}
	}
	scanf("%d",&n);
	while(n--){
		scanf("%s",s);
		for(i=0,num=1;i<18;i++)
			if(s[i]=='x')
				num=(num*10+10)%100007;
			else
				num=(num*10+(s[i]-'0'))%100007;
		for(i=0;i<vec[num].size();i++)
			if(!strcmp(vec[num][i].s,s)){
				printf("%d\n",vec[num][i].ans);
				break;
			}
		if(i>=vec[num].size())
			printf("No Info\n");
	}
	return 0;
}