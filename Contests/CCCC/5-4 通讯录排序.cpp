#include <bits/stdc++.h>
using namespace std;
struct node{
	int x;
	char s[2][22];
}p[12];
int n,i;
int cmp(node a,node b){
	return a.x<b.x;
}
int main(){
	cin>>n;
	for(i=0;i<n;i++)
		cin>>p[i].s[0]>>p[i].x>>p[i].s[1];
	sort(p,p+n,cmp);
	for(i=0;i<n;i++)
		printf("%s %d %s\n",p[i].s[0],p[i].x,p[i].s[1]);
	return 0;
}