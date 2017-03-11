#include <bits/stdc++.h>
using namespace std;
struct node{
	int id,s;
	char name[12];
}p[111111];
int n,i,c;
int cmp1(node a,node b){
	return a.id<b.id;
}
int cmp2(node a,node b){
	int k=strcmp(a.name,b.name);
	if(!k)
		return a.id<b.id;
	return k<0;
}
int cmp3(node a,node b){
	if(a.s==b.s)
		return a.id<b.id;
	return a.s<b.s;
}
int main(){
	scanf("%d %d",&n,&c);
	for(i=0;i<n;i++)
		scanf("%d %s %d",&p[i].id,p[i].name,&p[i].s);
	if(c<2)
		sort(p,p+n,cmp1);
	else if(c<3)
		sort(p,p+n,cmp2);
	else
		sort(p,p+n,cmp3);
	for(i=0;i<n;i++)
		printf("%06d %s %d\n",p[i].id,p[i].name,p[i].s);
	return 0;
}